/*
    Font.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19
*/
#include "../pieces/Font.hpp"
#include "../managers/ResourceManager.hpp"

// ! Glyph class.

Glyph::Glyph(GLuint      t_glyphID, 
             glm::ivec2  t_glyphSize, 
             glm::ivec2  t_glyphBearing, 
             GLint64     t_glpyhAdvance)
            : m_glyphID         (t_glyphID)
            , m_glyphSize       (t_glyphSize)
            , m_glyphBearing    (t_glyphBearing)
            , m_glpyhAdvance    (t_glpyhAdvance) {
                
}

GLuint Glyph::getGlyphID() { 
    return m_glyphID; 
}

glm::ivec2 Glyph::getGlyphSize() { 
    return m_glyphSize; 
}

glm::ivec2 Glyph::getGlyphBearing() { 
    return m_glyphBearing;
}

GLint64 Glyph::getGlyphAdvance() { 
    return m_glpyhAdvance; 
}

// ! Font class.

Font::Font(const std::string &t_fontPath, GLuint t_fontSize) {

    m_name = t_fontPath;
    FT_Library library;

    if (FT_Init_FreeType(&library)) {
        std::cout << "Failed to init Library" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (FT_New_Face(library, t_fontPath.c_str(), 0, &m_face)) {
        std::cout << "Failed to load font: " + t_fontPath << std::endl;
        exit(EXIT_FAILURE);
    }

    FT_Set_Pixel_Sizes(m_face, 0, t_fontSize);

    createOpenGLObject();

    FT_Done_Face(m_face);
    FT_Done_FreeType(library);

    ResourceManager<Font>::registerObject(*this);
}

GLvoid Font::createOpenGLObject() {

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  for (GLubyte ch = 0; ch < 128; ch++) {

    if (FT_Load_Char(m_face, ch, FT_LOAD_RENDER)) {
      std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
      continue;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 
                 0, GL_RED, 
                 m_face->glyph->bitmap.width,
                 m_face->glyph->bitmap.rows, 
                 0, 
                 GL_RED, 
                 GL_UNSIGNED_BYTE,
                 m_face->glyph->bitmap.buffer);

    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_IMAGE_HEIGHT, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glm::ivec2 size(m_face->glyph->bitmap.width, 
                    m_face->glyph->bitmap.rows);

    glm::ivec2 bearing(m_face->glyph->bitmap_left, 
                       m_face->glyph->bitmap_top);

    Glyph *character = new Glyph(texture, 
                     size, 
                     bearing, 
                     m_face->glyph->advance.x);
                     
    m_registry[ch] = character;
  }

  glBindTexture(GL_TEXTURE_2D, 0);   
}

Font::Registry Font::getGlyphs() {
    return m_registry;
}

std::string Font::getName() {
    return m_name;
}