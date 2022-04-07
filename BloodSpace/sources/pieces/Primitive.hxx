/*
    Primitive.hxx
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "Primitive.hpp"

// ! Implementation struct.

template <class Type> 
template <class Arg> 
Type Primitive::Implementation<Type>::parsePointers(const Arg &t_arg, int t_argSize) {

  int returnTypeSize = sizeof(Type) / sizeof(1);
  auto *firstElement = (float *)((void *)t_arg.begin());

  Type result;

  int i;
  for (i = 0; i < returnTypeSize; i++) {
    (i < t_argSize)
    ? result[i] = *(firstElement++)
    : result[i] = *(firstElement-1);      
  }

  return result;  
}

template <class Type> 
template <class... Args>
Type Primitive::Implementation<Type>::createVector(Args... t_args) {

  auto arguments = {t_args...};
  int scalarsCount = 0;
  int vecCount = 0;


  for (auto &ite: arguments) {
    (sizeof(ite) / sizeof(float) == 1)
    ? scalarsCount++
    : vecCount++;
  }

  int scalarsFromVec = sizeof(*arguments.begin()) / sizeof(1.0f);

  return (vecCount >= 1)
  ? Implementation<Type>::parsePointers(arguments, scalarsFromVec) 
  : Implementation<Type>::parsePointers(arguments, scalarsCount);
}

// ! Setter struct.

template <class... Args> 
GLvoid Primitive::setSize(Args... t_args) {
  m_size = Implementation<glm::vec2>::createVector(t_args...);
}

template <class... Args> 
GLvoid Primitive::setPosition(Args... t_args) {
 m_position = Implementation<glm::vec2>::createVector(t_args...);
}

template <class... Args> 
GLvoid Primitive::setColor(Args... t_args) {
  m_color = Implementation<glm::vec4>::createVector(t_args...);
}