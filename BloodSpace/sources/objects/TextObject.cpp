/*
    TextObject.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef TEXT_OBJECT_HPP
#define TEXT_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../objects/BaseObject.hpp"

class TextObject : public BaseObject {
    private:
 
        glm::vec2          *m_position;
    public:
        TextObject();
        GLvoid objectLogic();
    
}; // TEXT_OBJECT
#endif // TEXT_OBJECT_HPP