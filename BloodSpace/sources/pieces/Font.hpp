/*
    Font.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/
#ifndef FONT_HPP
#define FONT_HPP

#include "../utils/CommonIncludes.hpp"

struct Glyph {
private:
  GLuint        m_glyphID;
  glm::ivec2    m_glyphSize;
  glm::ivec2    m_glyphBearing;
  GLint64       m_glpyhAdvance;

public:
  Glyph(GLuint      t_glyphID, 
        glm::ivec2  t_glyphSize, 
        glm::ivec2  t_glyphBearing, 
        GLint64     t_glpyhAdvance);

  GLuint        getGlyphID();
  glm::ivec2    getGlyphSize();
  glm::ivec2    getGlyphBearing();
  GLint64       getGlyphAdvance();
};


class Font {
    private:
        typedef std::map<GLchar, Glyph*> Registry;

        Registry    m_registry;
        std::string m_name;
        FT_Face     m_face;

        GLvoid createOpenGLObject();

    public:
        Font(const std::string &t_fontPath, GLuint t_fontSize);
        Registry getGlyphs();
        std::string getName();

}; // Font

#endif //FONT_HPP