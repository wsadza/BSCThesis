/*
    Text.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#ifndef TEXT_HPP
#define TEXT_HPP

#include "../utils/CommonIncludes.hpp"
#include "Primitive.hpp"
#include "Font.hpp"

class Text {
    private:

        Font            *m_font;
        Primitive       *m_primitive;
        glm::vec2       m_position;
        glm::vec4       *m_color;
        std::string     m_name;
        std::string     m_textRender;

        GLvoid textShift();
    public:
        Text(const std::string &t_textRender, 
             Primitive &t_primitive, 
             const std::string &t_fontPath = "resources/fonts/04b_30.ttf", 
             GLuint t_fontSize = 15);
        
        std::string getName();
        std::string getText();        
        glm::vec2  &getPosition();
        glm::vec4  &getColor();
        Font        getFont();
}; // Text 

#endif //TEXT_HPP