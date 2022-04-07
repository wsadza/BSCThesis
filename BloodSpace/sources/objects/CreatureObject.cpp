/*
    Creature_Object.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#include "../objects/CreatureObject.hpp"
#include "../managers/ResourceManager.hpp"
#include "../utils/Settings.hpp"
#include "../objects/CursorObject.hpp"
#include "../utils/SharedResources.hpp"

// ! CreatureObject class.

CreatureObject::CreatureObject() : BaseObject() {

    setImage("resources/sprites/Enemy/Enemy_0/enemy_0.png");
    setShader("resources/shaders/image.shader");

    m_motion = new ObjectMotion<CreatureObject>(getPrimitive().getPosition(), getPrimitive().getSize());

    m_animation = new Animation("resources/sprites/Enemy/Enemy_0/enemy_0.png", getImage());

    m_particleGenerator = new ParticleGenerator("resources/shaders/image.shader", 10);
    m_particleGenerator->setDrains(15.0f, 0.25f, 10.0f);
    m_particleGenerator->setImage("resources/sprites/Enemy/Enemy_0/enemy_0.png");
    m_particleGenerator->setScopeColor(0.0f, 0.0f, 1.0f);
    m_particleGenerator->setSpawnPointRange(getPrimitive().getPosition());
}

GLvoid CreatureObject::objectLogic() { 
    m_motion->objectMove(); 
    m_animation->play();
    m_particleGenerator->render();
}
