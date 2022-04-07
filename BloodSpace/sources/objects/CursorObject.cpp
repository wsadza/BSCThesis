/*
    Base_Object.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../objects/CursorObject.hpp"
#include "../utils/SharedResources.hpp"
#include "../managers/InputManager.hpp"

glm::vec2 *CursorObject::m_cursorPosition;
ParticleGenerator *CursorObject::m_particleGenerator;

CursorObject::CursorObject(const std::string &t_pathImage) : BaseObject() {
    
    setImage(t_pathImage);
    getPrimitive().setSize(1.0f);

    m_cursorPosition = &getPrimitive().getPosition();

    GLFWcursor  *glfwCursor;
    GLFWimage   *glfwImage = new GLFWimage();

    glfwImage->pixels = stbi_load(t_pathImage.c_str(), &glfwImage->height, &glfwImage->width, nullptr, 0);

    glfwCursor = glfwCreateCursor(glfwImage, 0, 0);

    glfwSetCursor(SharedResources::window, glfwCursor);

    m_particleGenerator = new ParticleGenerator("resources/shaders/image.shader");
    m_particleGenerator->setDrains(15.0f, 0.25f, 10.0f);
    m_particleGenerator->setImage("resources/sprites/cursors/cursor_0/cursor_particle.png");
    m_particleGenerator->setSpawnPointRange(getPrimitive().getPosition(), getPrimitive().getSize());
    m_particleGenerator->setParticleSize(glfwImage->width, glfwImage->height);
}

CursorObject &CursorObject::initCursor(const std::string &t_pathImage) {
    static CursorObject cursorObject(t_pathImage);
    return cursorObject;
}

GLvoid CursorObject::cursorLogic() {
    *m_cursorPosition = InputManager::getMousePosition();

}

GLvoid CursorObject::showCursor(GLboolean t_hideCursor) {

    (t_hideCursor)
    ? glfwSetInputMode(SharedResources::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL)
    : glfwSetInputMode(SharedResources::window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

GLvoid CursorObject::cursorRender() {
    m_particleGenerator->render();
}