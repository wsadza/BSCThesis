/*
    Base_Object.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../pieces/Image.hpp"
#include "../pieces/Text.hpp"
#include "../pieces/Shader.hpp"

class BaseObject {
    private:
        Primitive   *m_primitive;
        Image       *m_image;
        Shader      *m_shader;
        Text        *m_text;
        BaseObject  *m_savedObject;
    public:
        BaseObject();
        GLvoid setPrimitive(glm::vec2 t_size, glm::vec2 t_position, glm::vec4 t_color);
        GLvoid setImage(const std::string &t_pathImage);
        GLvoid setShader(const std::string &t_pathShader);
        GLvoid setText(const std::string &t_textRender);

        Primitive &getPrimitive();
        Image     &getImage();
        Shader    &getShader();
        Text      &getText();

        GLvoid objectRender();
        GLvoid saveObject();
        GLvoid restoreObject();
}; // BaseObject

#endif // BASE_OBHECT_HPP