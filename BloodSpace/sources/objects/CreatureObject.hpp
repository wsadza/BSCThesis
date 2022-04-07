/*
    Base_Object.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef CREATURE_OBJECT_HPP
#define CREATURE_OBJECT_HPP

#include "../utils/CommonIncludes.hpp"
#include "../objects/BaseObject.hpp"
#include "../animation/Animation.hpp"
#include "../generators/ParticleGenerator.hpp"
#include "../objects/objectsUtils/ObjectMotion.hpp"

class CreatureObject : public BaseObject {
    private:
        ObjectMotion<CreatureObject> *m_motion;
        
        Animation          *m_animation;
        ParticleGenerator  *m_particleGenerator;
    public:
        CreatureObject();
        GLvoid objectLogic();  
    
 
}; // CreatureObject
#endif // CREATURE_OBJECT_HPP