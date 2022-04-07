/*
    Animation.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/        
#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "../utils/CommonIncludes.hpp"
#include "../pieces/Image.hpp"

class Animation {
    public:
        Animation(const std::string &t_framePath, Image &t_imagePointer);      
        GLvoid play(); 
        GLboolean animationFinish();
        GLvoid animationStop();
    private:
        GLboolean checkIsAnimation(const std::string& t_imagePath);
        GLvoid loadFrames(const std::string &t_framePath);

        std::vector<Image>  m_frames;
        Image              *m_imagePointer;
        GLuint              m_frameCounter;
        GLfloat             m_currentDuration;
        GLboolean           m_isAnimationEnd;
        GLboolean           m_stop;
}; // Animation

#endif // ANIMATION_HPP