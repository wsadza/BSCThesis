/*
    Image.cpp
    Purpose: Load image from file.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../pieces/Image.hpp"
#include "../managers/ResourceManager.hpp"

Image::Image() {
    
}

Image::Image(const std::string &t_pathToImage) {

    m_pixels = stbi_load(t_pathToImage.c_str(), &m_size.x, &m_size.y, nullptr, 0);
    if (!m_pixels) {
        std::cout << "The sprite cannot be open: " + t_pathToImage << std::endl;
        exit(EXIT_FAILURE);
    }

    m_id = createOpenGLObject();
    m_name = t_pathToImage;

    ResourceManager<Image>::registerObject(*this);
}

GLvoid Image::use() {
    glBindTexture(GL_TEXTURE_2D, m_id); 
}

std::string Image::getName() {
    return m_name;
}

glm::vec2 Image::getSize() {
    return m_size;
}

GLuint Image::createOpenGLObject() {

  GLuint imageID;
  glGenTextures(1, &imageID);
  glBindTexture(GL_TEXTURE_2D, imageID);

  glPixelStorei(GL_UNPACK_ROW_LENGTH, m_size.x);
  glPixelStorei(GL_UNPACK_IMAGE_HEIGHT, m_size.y);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  glGenerateMipmap(GL_TEXTURE_2D);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x,
               m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE,
               m_pixels);

  glBindTexture(GL_TEXTURE_2D, 0);

  return imageID;
}