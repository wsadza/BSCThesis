/*
    Dash.hpp
    Purpose: -.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef DASH_HPP
#define DASH_HPP

#include "../utils/CommonIncludes.hpp"

class Dash {
    private:
        glm::vec4 *m_colorPointer;
        GLboolean m_finished;
        GLboolean m_reverse;
        GLboolean m_dashEnd;
        GLboolean m_reverseEnd;
    public:
        Dash(glm::vec4 *t_colorPointer);
        GLboolean play();
        GLvoid reset();
        GLvoid reverse();

        GLboolean reverseEnd();
        GLboolean dashEnd();
}; // Dash

#endif // DASH