/*
    Primitive.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "Primitive.hpp"

Primitive::Primitive() { }

glm::vec2 &Primitive::getSize() { return m_size; }

glm::vec2 &Primitive::getPosition() { return m_position; }

glm::vec4 &Primitive::getColor() { return m_color; }
