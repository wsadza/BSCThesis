/*
    Dash.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../effects/Dash.hpp"
#include "../utils/SharedResources.hpp"

// ! Dash

Dash::Dash(glm::vec4 *t_colorPointer) 
    : m_colorPointer(t_colorPointer)
    , m_finished(false)
    , m_reverse(false)
    , m_reverseEnd(false)
    , m_dashEnd(false) {

}

GLboolean Dash::play() {

    if (!m_reverse) {
        if (m_colorPointer->w >= 0.0f) {
            m_colorPointer->w -= SharedResources::deltaTime;
        } else {
            m_finished = true;
            m_dashEnd = true;
        }    
    }
    else {
        if (m_colorPointer->w <= 1.0f) {
            m_colorPointer->w += SharedResources::deltaTime;
        } else {
            m_finished = true;
            m_reverseEnd = true;
        }            
    }

    return (m_finished)
    ? true
    : false;
}

GLvoid Dash::reset() {
    m_finished = false;
    m_reverse = false;
}

GLvoid Dash::reverse() {
    (m_reverse)
    ? m_reverse = false
    : m_reverse = true;
}

GLboolean Dash::reverseEnd() {
    return m_reverseEnd;
}

GLboolean Dash::dashEnd() {
    return m_dashEnd;
}