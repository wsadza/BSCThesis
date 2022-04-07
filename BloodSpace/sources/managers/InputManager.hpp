/*
    InputManager.hpp
    Purpose: Input manager.

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/
#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "../utils/CommonIncludes.hpp"

class InputManager {
    private:
        InputManager();
        static GLboolean *m_mouseKeys;
        static GLboolean *m_keyboardKeys;
        static glm::vec2 m_mousePosition;
    public:
        static InputManager &initInputManager();
        static GLboolean *getMouseKeys();
        static GLboolean *getKeyboardKeys();
        static glm::vec2 &getMousePosition();
};

#endif // INPUT_MANAGER_HPP
