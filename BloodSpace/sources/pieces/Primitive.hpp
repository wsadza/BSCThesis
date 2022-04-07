/*
    Primitive.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include "../utils/CommonIncludes.hpp"

class Primitive {
private:

  template<class Type>
  struct Implementation {
    template <class Arg>
    static Type parsePointers(const Arg &t_arg, int t_argSize);

    template <class... Args> 
    static Type createVector(Args... t_args);
  }; // Implementation
  
  glm::vec2 m_size;
  glm::vec2 m_position;
  glm::vec4 m_color;

public:
  Primitive();

  template <class... Args> GLvoid 
  setSize(Args... t_args);

  template <class... Args> GLvoid 
  setPosition(Args... t_args);

  template <class... Args> GLvoid 
  setColor(Args... t_args);

  glm::vec2 &getSize();
  glm::vec2 &getPosition();
  glm::vec4 &getColor();
};

static GLboolean checkPrimitiveCollision(Primitive t_one, Primitive t_two) {

    bool collisionX = t_one.getPosition().x + t_one.getSize().x >= t_two.getPosition().x &&
                      t_two.getPosition().x + t_two.getSize().x >= t_one.getPosition().x;

    bool collisionY = t_one.getPosition().y + t_one.getSize().y >= t_two.getPosition().y &&
                      t_two.getPosition().y + t_two.getSize().y >= t_one.getPosition().y;

    return collisionX && collisionY;
}


#include "Primitive.hxx"


#endif //PRIMITIVE_HPP