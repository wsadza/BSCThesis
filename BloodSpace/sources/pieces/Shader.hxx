/**
    Shader.hxx
    Purpose: Build shader program from text file.

    @author Igor Sadza
    @version 1.0 - 30/01/19
    *TODO: - Create function thath check file format give to construtor. 
           - Shader files have format .shader so.. 
*/

#include "Shader.hpp"

// ! Shader::Utils struct.

template <class Type_0, std::size_t Number, class Type_1>
auto Shader::makeArray(Type_1 t_var) -> std::array<Type_0, Number> {

  std::array<Type_0, Number> result;
  float *p = (float *)(void *)(&t_var);
  for (int i = 0; i < Number; i++) {
    result[i] = *p++;
  }
  return result;
}

template <class Type>
GLvoid Shader::sendVariable(const std::string &t_uniformName, Type t_value) {

  use();
  int location = glGetUniformLocation(m_shaderProgram, t_uniformName.c_str());

  if (typeid(Type) == typeid(float)) {
    auto array = makeArray<float, 1>(t_value);
    glUniform1f(location, array[0]);
  } 
  else 
  if (typeid(Type) == typeid(glm::vec2)) {
    auto array = makeArray<float, 2>(t_value);
    glUniform2f(location, array[0], array[1]);
  } 
  else 
  if (typeid(Type) == typeid(glm::vec3)) {
    auto array = makeArray<float, 3>(t_value);
    glUniform3f(location, array[0], array[1], array[2]);
  } 
  else 
  if (typeid(Type) == typeid(glm::vec4)) {
    auto array = makeArray<float, 4>(t_value);
    glUniform4f(location, array[0], array[1], array[2], array[3]);
  } 
  else 
  if (typeid(Type) == typeid(glm::mat4)) {
    auto array = makeArray<float, 16>(t_value);
    glUniformMatrix4fv(location, 1, GL_FALSE,
                       glm::value_ptr(glm::make_mat4(&array[0])));
  }
}