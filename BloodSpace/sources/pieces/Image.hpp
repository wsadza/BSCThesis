/*
    Image.hpp
    Purpose: Load image from file.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../utils/CommonIncludes.hpp"

class Image {
    private:

        GLuint          m_id;      
        std::string     m_name;
        GLubyte*        m_pixels;
        glm::ivec2      m_size;        
    
        GLuint createOpenGLObject();

    public:
        Image();
        Image(const std::string &t_imagePath);
        std::string getName();  
        glm::vec2 getSize();        
        GLvoid use();    
}; // Image

#endif //IMAGE_HPP