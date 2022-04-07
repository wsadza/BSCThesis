/*
    ObjectLogo.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef LOGO_OBJECT_HPP
#define LOGO_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../objects/BaseObject.hpp"
#include "../animation/Animation.hpp"
#include "../effects/Dash.hpp"

class ObjectLogo : public BaseObject {
    private:
        Animation          *m_animation;
        Dash               *m_dash;
    public:
        ObjectLogo();
        GLvoid objectLogic(); 
 
}; // Logo
#endif // LOGO_OBJECT_HPP