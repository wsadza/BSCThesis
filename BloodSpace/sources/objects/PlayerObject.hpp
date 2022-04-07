/*
    PlayerObject.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef PLAYER_OBJECT_HPP
#define PLAYER_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../objects/BaseObject.hpp"
#include "../animation/Animation.hpp"
#include "../generators/ParticleGenerator.hpp"
#include "sources/objects/objectsUtils/ObjectShot.hpp"

class PlayerObject : public BaseObject {
    private:
        std::vector<ObjectShot> m_objectShots;

        GLuint              m_playerLife;
        GLfloat             m_playerVelocity;
        
        Animation          *m_animation;
        glm::vec2          *m_position;
        GLvoid playerMove();
    public:
        PlayerObject();
        GLvoid objectLogic();
        std::vector<ObjectShot> getShots();
    
 
}; // PlayerObject
#endif // PLAYER_OBJECT_HPP