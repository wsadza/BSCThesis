/*
    ObjectMotion.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/

#include "sources/objects/objectsUtils/ObjectMotion.hpp"
#include "sources/utils/Settings.hpp"
#include "sources/objects/CursorObject.hpp"

template<class Type>
ObjectMotion<Type>::ObjectMotion(glm::vec2 &t_objectPos, 
                                 glm::vec2 &t_objectSiz, 
                                 ObjectBehavior t_behavior,
                                 ObjectType t_type)
    : m_type(t_type)
    , m_behavior(t_behavior) {

    randomiseDirection();
    m_objectPos = &t_objectPos;
    m_objectSiz = &t_objectSiz;
}

template<class Type>
GLvoid ObjectMotion<Type>::objectMove() {

    if(m_type == ObjectType::LIVING) {

        if (m_movementDestanation.x > m_objectPos->x) {
            m_objectPos->x += 0.5f;
        } else {
            m_objectPos->x -= 0.5f;
        }

        if (m_movementDestanation.y > m_objectPos->y) {
            m_objectPos->y += 0.5f;
        } else {
            m_objectPos->y -= 0.5f;
        }

        if (m_movementDestanation == *m_objectPos) {
            randomiseDirection();            
        }

        if(m_behavior == ObjectBehavior::FOLLOW) {
            checkPlayerPosition();        
        }
    }
    else {
         m_objectPos->y += 0.5f;
    }
}

template<class Type>
GLvoid ObjectMotion<Type>::checkPlayerPosition() {

    bool collisionX = m_objectPos->x + 150.0f >= CursorObject::getCursorPosition().x &&
                      CursorObject::getCursorPosition().x + 25.0f >= m_objectPos->x;

    bool collisionY = m_objectPos->y + 150.0f >= CursorObject::getCursorPosition().y &&
                      CursorObject::getCursorPosition().y + 25.0f >= m_objectPos->y;

    if(collisionX && collisionY) {
        m_movementDestanation = CursorObject::getCursorPosition();
    }
}

template<class Type>
GLvoid ObjectMotion<Type>::randomiseDirection() {
    srand (time(NULL));
    GLuint rand_C = rand() % 100;
    GLfloat rand_x = rand() % GLuint(Settings::windowWidth) + rand_C;
    GLfloat rand_y = rand() % GLuint(Settings::windowHeight) + rand_C;
    m_movementDestanation = glm::vec2(rand_x, rand_y);
}