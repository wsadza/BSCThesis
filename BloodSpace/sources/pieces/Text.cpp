/*
    Text.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#include "Text.hpp"

// ! Text class.

Text::Text(const std::string &t_text, Primitive &t_primitive, const std::string &t_fontPath, GLuint t_fontSize) 
        : m_primitive(&t_primitive)
        , m_textRender(t_text)
        , m_name(t_fontPath) {
        m_color = &t_primitive.getColor();
        m_font = new Font(t_fontPath, t_fontSize);
        textShift();
}

GLvoid Text::textShift() {

    std::string::const_iterator ite;
    for (ite = m_textRender.begin(); ite != m_textRender.end(); ite++) {
        Glyph glyph = *m_font->getGlyphs()[*ite];
        m_position.x += (glyph.getGlyphAdvance() >> 6);
    }

    m_position.y = m_font->getGlyphs()['H']->getGlyphSize().y;

    glm::vec2 newPosition;
    newPosition.y = m_primitive->getPosition().y + (m_primitive->getSize().y / 2.0f) - (m_position.y / 2);
    newPosition.x = m_primitive->getPosition().x + (m_primitive->getSize().x / 2.0f) - (m_position.x / 2);

    m_position = newPosition;
}

std::string Text::getName(){
    return m_name;
}
std::string Text::getText(){
    return m_textRender;
}    
glm::vec2 &Text::getPosition(){
    return m_position;
}
Font Text::getFont(){
    return *m_font;
}
glm::vec4 &Text::getColor() {
    return *m_color;
}