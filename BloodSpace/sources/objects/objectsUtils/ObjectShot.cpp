/*
    ObjectShot.cpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#include "sources/objects/objectsUtils/ObjectShot.hpp"

ObjectShot::ObjectShot(glm::vec2 t_startingPosition) : BaseObject() {
    setImage("resources/sprites/player/playerBullet/bullet.png");
    setShader("resources/shaders/image.shader");
    getPrimitive().setPosition(t_startingPosition);

    m_particleGenerator = new ParticleGenerator("resources/shaders/image.shader", 10);
    m_particleGenerator->setDrains(15.0f, 0.25f, 5.0f);
    m_particleGenerator->setImage("resources/sprites/player/playerBullet/bullet.png");
    m_particleGenerator->setScopeColor(0.0f, 1.0f, 1.0f);
    m_particleGenerator->setSpawnPointRange(getPrimitive().getPosition());
}

GLvoid ObjectShot::shotLogic() {
    getPrimitive().getPosition().y -= 10.0f;
    m_particleGenerator->render();
}