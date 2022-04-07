/*
    ObjectLogo.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#include "../objects/ObjectLogo.hpp"
#include "../states/StateMenu.hpp"
#include "../objects/CursorObject.hpp"
// ! CreatureObject class.

ObjectLogo::ObjectLogo() : BaseObject() {

    setImage("resources/sprites/animations/logo_0/0.png");
    setShader("resources/shaders/image.shader");
    getPrimitive().setSize(225.0f, 100.0f);
    getPrimitive().setPosition(287.5f, 225.0f);
    m_animation = new Animation("resources/sprites/animations/logo_0/0.png", getImage());
    getPrimitive().getColor().w = 0.0f;
    m_dash = new Dash(&getPrimitive().getColor());
    m_dash->reverse();
}

GLvoid ObjectLogo::objectLogic() {
    CursorObject::showCursor(false);
    
    m_dash->play();
    m_animation->play();
    if (m_animation->animationFinish()) {
        m_animation->animationStop();
        m_dash->reset();
    }

    if (m_dash->dashEnd()) {
        if(m_animation->animationFinish()) {
            StateMenu *stateMenu = new StateMenu();
        }        
    }

}