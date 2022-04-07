/*
    ObjectMotion.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef OBJECT_MOTION_HPP
#define OBJECT_MOTION_HPP

#include "sources/utils/CommonIncludes.hpp"

enum class ObjectBehavior {FOLLOW, RUN, FREELY};
enum class ObjectType {LIVING, STATIC};

template<class Type>
class ObjectMotion {
    private:
        glm::vec2      *m_objectPos;
        glm::vec2      *m_objectSiz;
        ObjectBehavior  m_behavior;
        ObjectType      m_type;
        glm::vec2       m_movementDestanation;

        GLvoid checkPlayerPosition();
        GLvoid randomiseDirection();
        GLvoid startingPosition();
    public:
        ObjectMotion(glm::vec2 &t_objectPos,
                     glm::vec2 &t_objectSiz, 
                     ObjectBehavior t_behavior = ObjectBehavior::FOLLOW,
                     ObjectType t_objectType = ObjectType::LIVING);

        GLvoid objectMove();

}; //ObjectMotion

#include "sources/objects/objectsUtils/ObjectMotion.hxx"

#endif//OBJECT_MOTION_HPP