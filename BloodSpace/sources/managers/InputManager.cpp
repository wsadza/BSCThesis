/*
    InputManager.cpp
    Purpose: Input manager.

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/
#include "../managers/InputManager.hpp"

GLboolean *InputManager::m_mouseKeys;
GLboolean *InputManager::m_keyboardKeys;
glm::vec2 InputManager::m_mousePosition;

InputManager::InputManager() {
    m_mouseKeys = new GLboolean[5];
    m_keyboardKeys = new GLboolean[5];

    for (int i = 0; i < 5; i++) {
        m_mouseKeys[i] = false;
        m_keyboardKeys[i] = false;
    }
}

InputManager &InputManager::initInputManager() {
    static InputManager inputManager;
    return inputManager;
}

GLboolean *InputManager::getMouseKeys() {
    return m_mouseKeys;        
}

GLboolean *InputManager::getKeyboardKeys() {
    return m_keyboardKeys;
}

glm::vec2 &InputManager::getMousePosition() {
    return m_mousePosition;
}