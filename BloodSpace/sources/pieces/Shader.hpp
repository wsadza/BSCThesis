/**
    Shader.hpp
    Purpose: Build shader program from text file.

    @author Igor Sadza
    @version 1.0 - 30/01/19
    
    *TODO: - Create function thath check file format give to construtor. 
           - Shader files have format .shader so.. 
*/

#ifndef SHADER_HPP
#define SHADER_HPP

#include "../utils/CommonIncludes.hpp"

class Shader {
private:

    template <class Type_0, std::size_t Number, class Type_1>
    auto makeArray(Type_1 t_var) -> std::array<Type_0, Number>;

    GLuint        m_shaderProgram;
    std::string   m_name;

    GLvoid link(GLuint t_shaderID, GLuint t_programID);
    GLvoid init(GLuint t_shaderID, const std::string &t_source);

public:

    Shader(const std::string &t_shaderPath);

    GLvoid use();
    std::string getName();
    
    template <class Type>  
    GLvoid sendVariable(const std::string &t_uniformName, Type t_value);    
};

#include "Shader.hxx"

#endif // SHADER_HPP