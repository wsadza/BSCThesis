/*
    PlayerObject.cpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/

#include "../objects/PlayerObject.hpp"
#include "../managers/InputManager.hpp"
#include "../utils/SharedResources.hpp"

PlayerObject::PlayerObject() 
: BaseObject() {

    m_playerVelocity = 5.0f;
    setImage("resources/sprites/animations/player_0/0.png");
    setShader("resources/shaders/image.shader");

    m_animation = new Animation("resources/sprites/animations/player_0/0.png", getImage());
    m_position = &getPrimitive().getPosition();
    *m_position = glm::vec2(350, 450);
}

GLvoid PlayerObject::objectLogic() {
    playerMove();
    m_animation->play();

    for (int i = 0; i < m_objectShots.size(); i++) {
        m_objectShots[i].shotLogic();
        m_objectShots[i].objectRender();
        if (m_objectShots[i].getPrimitive().getPosition().y < 0.0f) {
            m_objectShots.erase(m_objectShots.begin() + i);
        }
    }
}

GLfloat waitTime = 0.0f;
GLvoid PlayerObject::playerMove() {

    if (glfwGetKey(SharedResources::window, GLFW_KEY_UP) == GLFW_PRESS) {   
        m_position->y -= m_playerVelocity;

    } else if (glfwGetKey(SharedResources::window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        m_position->y += m_playerVelocity;
    }

    if (glfwGetKey(SharedResources::window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        m_position->x += m_playerVelocity;
    } else if(glfwGetKey(SharedResources::window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        m_position->x -= m_playerVelocity;
    }


    waitTime += SharedResources::deltaTime;
    if(waitTime > 0.2f) {
        if (glfwGetKey(SharedResources::window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            ObjectShot shotObject(getPrimitive().getPosition() + getPrimitive().getSize().x / 2 - 5.0f);
            m_objectShots.push_back(shotObject);
            InputManager::getKeyboardKeys()[GLFW_KEY_SPACE] = false;
        }
        waitTime = 0.0f;
    }
}


std::vector<ObjectShot> PlayerObject::getShots() {
    return m_objectShots;
}
