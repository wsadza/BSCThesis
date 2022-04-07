/*
    WidgetButton.cpp
    Purpose: Widget button

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#include "sources/widgets/ButtonWidget.hpp"
#include "../parsers/FileParser.hpp"
#include "../objects/CursorObject.hpp"
#include "../managers/InputManager.hpp"

WidgetButton::WidgetButton(const std::string &t_sourceForInitialization) : Widget() {
  
  for (auto &ite :FileParser::getParasedVariables(t_sourceForInitialization)) {
    if (ite.m_key == "Position") {
        getWidgetObject().setPrimitive(glm::vec2(1.0f), FileParser::parseVariable<glm::vec2>(ite.m_variable), glm::vec4(1.0f));
    } else if (ite.m_key == "Image") {
        getWidgetObject().setImage(ite.m_variable);
    } else if (ite.m_key == "Shader") {
        getWidgetObject().setShader(ite.m_variable);
    } else if (ite.m_key == "Text") {
       getWidgetObject().setText(ite.m_variable);
    } else if (ite.m_key == "NextState") {
      m_nextState = ite.m_variable;
    }
  }
  getWidgetObject().getPrimitive().getColor().w = 0.0f;
  m_dash = new Dash(&getWidgetObject().getPrimitive().getColor());
  m_dash->reverse();

  getWidgetObject().saveObject();
  blockInput() = false;
  m_clicked = false;
}

GLboolean WidgetButton::widgetCollision() {

    bool collisionX = CursorObject::getCursorPosition().x + 1.0f >= getWidgetObject().getPrimitive().getPosition().x &&
                      getWidgetObject().getPrimitive().getPosition().x + getWidgetObject().getPrimitive().getSize().x >= CursorObject::getCursorPosition().x;

    bool collisionY = CursorObject::getCursorPosition().y + 1.0f >= getWidgetObject().getPrimitive().getPosition().y &&
                      getWidgetObject().getPrimitive().getPosition().y + getWidgetObject().getPrimitive().getSize().y >= CursorObject::getCursorPosition().y;


    return collisionX && collisionY;
}

GLvoid WidgetButton::checkClick() {

  getWidgetObject().getPrimitive().setColor(1.0f);
  if (widgetCollision()) {
   getWidgetObject().getPrimitive().setColor(0.85f, 0.85f, 0.85f, 1.0f);

    if (InputManager::getMouseKeys()[GLFW_MOUSE_BUTTON_1] && !blockInput()) {
      getWidgetObject().getText().getPosition().y += 0.7f;
      m_clicked = true;
      blockInput() = true;
    }

  } else if (blockInput() == true){
    getWidgetObject().getText().getPosition().y -= 0.7f;
    blockInput() = false;
    m_clicked = false;
  }
}

GLvoid WidgetButton::widgetLogic() {
  m_dash->play();
  if (m_dash->reverseEnd() && !m_clicked) {
    checkClick();
  }
}

GLvoid WidgetButton::widgetRender() {
  getWidgetObject().objectRender();
}

std::string WidgetButton::getNextState() {
  return m_nextState;
}

GLboolean WidgetButton::clicked() {
  return m_clicked;
}