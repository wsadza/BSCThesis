/*
    Base_Object.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef CURSOR_OBJECT_HPP
#define CURSOR_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../generators/ParticleGenerator.hpp"
#include "BaseObject.hpp"


class CursorObject : public BaseObject {
    private:
        CursorObject(const std::string &t_pathImage);
        static Primitive m_cursorPrimitive;
        static glm::vec2 *m_cursorPosition;
        static ParticleGenerator *m_particleGenerator;
    public:
        static CursorObject &initCursor(const std::string &t_pathImage);
        
        static glm::vec2 getCursorPosition() {
            return *m_cursorPosition;
        }

        static GLvoid showCursor(GLboolean t_hideCursor = false);
        static GLvoid cursorLogic();
        static GLvoid cursorRender();

}; // CursorObject

#endif // BASE_OBHECT_HPP