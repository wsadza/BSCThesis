/*
    StatePlayground.cpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/

#include "../states/StatePlayground.hpp"
#include "../objects/BaseObject.hpp"
#include "../objects/CreatureObject.hpp"
#include "../generators/ParticleGenerator.hpp"
#include "../generators/ObjectGenerator.hpp"
#include "../objects/PlayerObject.hpp"

static StatePlayground *statePlayground;
CreatureObject *createuObject;

ObjectGenerator<CreatureObject> *objectGenerator;

PlayerObject *playerObject;

StatePlayground::StatePlayground() {
  statePlayground = this;
  BaseState::Register("StatePlayground", statePlayground);
  BaseState::setInstance("StatePlayground");

  // particleGenerator = new ParticleGenerator("resources/shaders/rectangle.shader", 500, false);
  // particleGenerator->setDrains(0.0f, 0.25f, 120);
  // particleGenerator->setParticleSize(5.0f, 5.0f);
  // particleGenerator->setScopeColor(1.0f, 10.0f, 1.0f);
  // particleGenerator->setSpawnPointRange(0.0f, -600.0f, 800.0f, 600.0f);

  // baseObject = new BaseObject();
  // baseObject->setShader("resources/shaders/image.shader");
  // baseObject->setImage("resources/sprites/player/PNG/Player - UPPER - MOVE/StarCrusader-UP-2.png");
  // baseObject->getPrimitive().setPosition(500.0f, 400.0f);
  
  objectGenerator = new ObjectGenerator<CreatureObject>(10);
  createuObject = new CreatureObject();
  playerObject = new PlayerObject();
}

GLvoid StatePlayground::stateBackground() {
  
}

GLvoid StatePlayground::stateLogic() {

  objectGenerator->generateObject();
  objectGenerator->generatedObjectLogic();
  objectGenerator->generatedObjectRender();

  playerObject->objectRender();
  playerObject->objectLogic();  


  // particleGenerator->render();



  for(auto& ite: objectGenerator->getObjects()) {
    if (checkPrimitiveCollision(playerObject->getPrimitive(), ite.getPrimitive())) {
      glfwSetWindowShouldClose(SharedResources::window, GLFW_TRUE);
    }
  }
}

GLvoid StatePlayground::stateRender() { 

}