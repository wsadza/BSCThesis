/*
    StateMenu.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/

#include "../states/StateMenu.hpp"
#include "../objects/BaseObject.hpp"
#include "../objects/PlayerObject.hpp"
#include "../objects/CursorObject.hpp"
#include "../parsers/FileParser.hpp"
#include "../states/StatePlay.hpp"
#include "../utils/SharedResources.hpp"

static StateMenu *stateMenu;

StateMenu::StateMenu() {
  stateMenu = this;
  BaseState::Register("StateMenu", stateMenu);
  //BaseState::setInstance("StateMenu");

  // * TextFileParser works.
  FileParser tfp("resources/states/menu.state");
  for (auto& ite: tfp.getSections()) {
        if (ite.m_header == "WidgetButton") {
            WidgetButton widget(ite.m_source);
            m_widgets.push_back(widget);            
        }
  }

  m_particleGenerator = new ParticleGenerator("resources/shaders/particle.shader", 500, false);
  m_particleGenerator->setDrains(0.0f, 0.05f, 40);
  m_particleGenerator->setParticleSize(10.0f, 10.0f);
  m_particleGenerator->setScopeColor(1.0f, 0.0f, 0.0f);
  m_particleGenerator->setSpawnPointRange(0.0f, -600.0f, 800.0f, 600.0f);

  m_objectGenerator = new ObjectGenerator<CreatureObject>(3);
}

GLvoid StateMenu::stateBackground() {
    m_particleGenerator->render();
    m_objectGenerator->generateObject();
    m_objectGenerator->generatedObjectLogic();
    m_objectGenerator->generatedObjectRender();
}

GLvoid StateMenu::stateLogic() {
    CursorObject::cursorLogic();
    CursorObject::showCursor(true);
    
    for(auto& ite:m_widgets) {
        ite.widgetRender();
        if (ite.getNextState() == "Play" && ite.clicked()){
            StatePlay *statePlay = new StatePlay();              
        } else if (ite.getNextState() == "Option" && ite.clicked()) {
            
        } else if (ite.getNextState() == "Exit" && ite.clicked()) {
            glfwSetWindowShouldClose(SharedResources::window, GLFW_TRUE);
        }
    }
}

GLvoid StateMenu::stateRender() { 
    CursorObject::cursorRender();
    for(auto& ite:m_widgets) {
        ite.widgetLogic();
    }
}