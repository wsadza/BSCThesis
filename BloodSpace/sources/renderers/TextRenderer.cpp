/*
    TextRenderer.cpp
    Purpose: Render text.

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#include "../renderers/TextRenderer.hpp"
#include "../managers/ResourceManager.hpp"

GLuint TextRenderer::m_vao;
GLuint TextRenderer::m_vbo;
Shader *TextRenderer::m_textShader;

TextRenderer::TextRenderer() {

  m_textShader = new Shader("resources/shaders/text.shader");
  m_textShader->sendVariable("t_sampler", 0);

  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);

  glBindVertexArray(m_vao);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void * )(0 * sizeof(GLfloat)));
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);    
};

TextRenderer &TextRenderer::initRenderer() {
    static TextRenderer textRenderer;
    return textRenderer;
}

GLvoid TextRenderer::renderText(Text t_text) {

  m_textShader->use();
  
  glBindVertexArray(m_vao);

  std::string text = t_text.getText();
  std::string::const_iterator ite; 

  m_textShader->sendVariable("t_color", t_text.getColor());

 float lineLenght = 0.0f;

  for (ite = text.begin(); ite != text.end(); ite++) {
    
    Glyph glyph   = *t_text.getFont().getGlyphs()[*ite];
    Glyph glyph_H = *t_text.getFont().getGlyphs()['H'];

    float xpos = t_text.getPosition().x + lineLenght + glyph.getGlyphBearing().x;
    float ypos = t_text.getPosition().y + (glyph_H.getGlyphSize().y - glyph.getGlyphBearing().y);

    float w = glyph.getGlyphSize().x;
    float h = glyph.getGlyphSize().y;

    float vertices[6][4] = {
        { xpos,     ypos + h,   0.0, 1.0 },
        { xpos + w, ypos,       1.0, 0.0 },
        { xpos,     ypos,       0.0, 0.0 },

        { xpos,     ypos + h,   0.0, 1.0 },
        { xpos + w, ypos + h,   1.0, 1.0 },
        { xpos + w, ypos,       1.0, 0.0 }
    };

    glBindTexture(GL_TEXTURE_2D, glyph.getGlyphID());

      glBindBuffer(GL_ARRAY_BUFFER, m_vao);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
      glBindBuffer(GL_ARRAY_BUFFER, 0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindTexture(GL_TEXTURE_2D, 0);

    lineLenght += (glyph.getGlyphAdvance() >> 6);
  }   
}