/*
    TextRenderer.hpp
    Purpose: Render text.

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#ifndef TEXT_RENDERER_HPP
#define TEXT_RENDERER_HPP

#include "../utils/CommonIncludes.hpp"
#include "../pieces/Shader.hpp"
#include "../pieces/Text.hpp"

class TextRenderer {
    private:
        TextRenderer();
        static GLuint           m_vao;
        static GLuint           m_vbo;
        static Shader           *m_textShader;
    public:
        static TextRenderer     &initRenderer();
        static GLvoid           renderText(Text t_textObject);
};

#endif //TEXT_RENDERER_HPP