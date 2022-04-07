/*
    Animation.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/        
#include "../animation/Animation.hpp"
#include "../utils/SharedResources.hpp"

Animation::Animation(const std::string &t_framePath, Image &t_imagePointer) {

  m_stop = false;
  m_imagePointer = &t_imagePointer;
  m_frameCounter = 0;
  m_currentDuration = 0.0f;
  loadFrames(t_framePath);
}

GLboolean Animation::animationFinish() {
    return m_isAnimationEnd;
}

GLvoid Animation::animationStop() {
    m_stop = true;
}

GLboolean Animation::checkIsAnimation(const std::string& t_imagePath) {

    std::string modifiedPath = t_imagePath;
    size_t signPos;

    signPos = t_imagePath.find_last_of('.') - 1;
    modifiedPath.erase(modifiedPath.begin() + signPos, modifiedPath.end());
    modifiedPath += std::to_string(0) + ".png";

    glm::ivec2 size;
    GLubyte *pixels = stbi_load(modifiedPath.c_str(), &size.x, &size.y, nullptr, 0);

    return (pixels)
    ? true
    : false;
}

GLvoid Animation::play() {

    if (!m_stop) {
        if((m_currentDuration += SharedResources::deltaTime) >= 0.1f) {
            if (m_frameCounter < m_frames.size()) {
                *m_imagePointer = m_frames[m_frameCounter++];
                m_currentDuration = 0.0f;
            }
            else {
                m_frameCounter = 0;
                m_isAnimationEnd = true;
            }
        }       
    }
    
}

GLvoid Animation::loadFrames(const std::string &t_framePath) {

    std::string withoutExtension;
    std::string modifiedPath;
    size_t signPos;

    withoutExtension = t_framePath;
    signPos = t_framePath.find_last_of('.') - 1;
    withoutExtension.erase(withoutExtension.begin() + signPos, withoutExtension.end());
    modifiedPath = withoutExtension + std::to_string(0) + ".png";

    glm::ivec2 size;
    GLubyte *pixels;
    
    pixels = stbi_load(modifiedPath.c_str(), &size.x, &size.y, nullptr, 0);
        
    for (int i = 1; pixels; i++) {
        Image img = Image(modifiedPath);
        m_frames.push_back(img);

        modifiedPath = withoutExtension + std::to_string(i + 1) + ".png";
        pixels = stbi_load(modifiedPath.c_str(), &size.x, &size.y, nullptr, 0);
    }
}