/*
    StatePlay.cpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../states/StatePlay.hpp"
#include "../objects/CreatureObject.hpp"
#include "../states/StateMenu.hpp"

static StatePlay *statePlay;

CreatureObject * creatureObject;
std::vector<CreatureObject> x;


StatePlay::StatePlay() {
  statePlay = this;
  BaseState::Register("StatePlay", statePlay);
  //BaseState::setInstance("StatePlay");

  m_particleGenerator = new ParticleGenerator("resources/shaders/rectangle.shader", 500, false);
  m_particleGenerator->setDrains(0.0f, 0.0f, 120);
  m_particleGenerator->setParticleSize(3.0f, 3.0f);
  m_particleGenerator->setScopeColor(1.0f, 1.0f, 1.0f);
  m_particleGenerator->setSpawnPointRange(0.0f, -600.0f, 800.0f, 600.0f);

  m_playerObject = new PlayerObject();

  m_objectGenerator = new ObjectGenerator<CreatureObject>(500);

  creatureObject = new CreatureObject();
  creatureObject->getPrimitive().setPosition(glm::vec2(100.0f));
  x.push_back(*creatureObject);
}

GLvoid StatePlay::stateBackground() {
  m_particleGenerator->render();
}

GLvoid StatePlay::stateLogic() {
  CursorObject::showCursor(false);

  m_playerObject->objectLogic();
  m_objectGenerator->generateObject();

  if(glfwGetKey(SharedResources::window, GLFW_KEY_ESCAPE)) {
    StateMenu *stateMenu = new StateMenu();
  }
}

GLvoid StatePlay::stateRender() { 
  m_playerObject->objectRender();
  
  for (auto& ite: m_objectGenerator->getObjects()) {
    ite.objectRender();
    ite.objectLogic();
  }

  for (int i = 0; i < m_playerObject->getShots().size(); i++){
    for (int j = 0; j <  m_objectGenerator->getObjects().size(); j++) {
      if (checkPrimitiveCollision(m_playerObject->getShots()[i].getPrimitive(),  m_objectGenerator->getObjects()[j].getPrimitive())) {
         m_objectGenerator->getObjects().erase( m_objectGenerator->getObjects().begin() + j);
      }
    }
  }
}