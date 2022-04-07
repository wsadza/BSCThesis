/**
    Shader.cpp
    Purpose: Build shader program from text file.

    @author Igor Sadza
    @version 1.0 - 30/01/19
    *TODO: - Create function thath check file format give to construtor. 
           - Shader files have format .shader so.. 
*/

#include "Shader.hpp"
#include "../utils/Settings.hpp"
#include "../parsers/FileParser.hpp"
#include "../managers/ResourceManager.hpp"

// ! Shader class.

Shader::Shader(const std::string &t_path)  {

  FileParser fileParser(t_path);
  std::vector<std::string> shaders;
  
  m_name = t_path;

  m_shaderProgram = glCreateProgram();
  unsigned shaderID = 0;
  for (auto &i : fileParser.getSections()) {
    if (i.m_header == "VERTEX-SHADER") {
      shaderID = glCreateShader(GL_VERTEX_SHADER);
    } else 
    if (i.m_header == "FRAGMENT-SHADER") {
      shaderID = glCreateShader(GL_FRAGMENT_SHADER);
    } else 
    if (i.m_header == "GEOMETRY-SHADER") {
      shaderID = glCreateShader(GL_GEOMETRY_SHADER);
    }
    init(shaderID, i.m_source);
    link(shaderID, m_shaderProgram);
    glDeleteShader(shaderID);
  }

  glm::mat4 projectionMatrix =
      glm::ortho(0.0f, Settings::windowWidth, Settings::windowHeight, 0.0f, -1.0f, 1.0f);

  use();
  sendVariable("t_projection", projectionMatrix);
  ResourceManager<Shader>::registerObject(*this);
}

GLvoid Shader::link(unsigned t_shaderID, unsigned t_programID) {

  int success;
  char infoLog[512];

  glAttachShader(t_programID, t_shaderID);
  glLinkProgram(t_programID);
  glGetProgramiv(t_programID, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetProgramInfoLog(t_programID, sizeof(infoLog), NULL, infoLog);
    std::cout << infoLog << std::endl;
    std::runtime_error(std::string(infoLog));
  }
}

GLvoid Shader::init(unsigned t_shaderID, const std::string &t_source) {

  int success;
  char infoLog[512];
  const char *src = t_source.c_str();
  glShaderSource(t_shaderID, 1, &src, NULL);
  glCompileShader(t_shaderID);
  glGetShaderiv(t_shaderID, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(t_shaderID, 512, NULL, infoLog);
    std::cout << infoLog << std::endl;
    std::runtime_error(std::string(infoLog));
  }
}

GLvoid Shader::use() { 
    glUseProgram(m_shaderProgram); 
}

std::string Shader::getName() { return m_name; }

