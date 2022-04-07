/*
    main.cpp
    Purpose: Main file.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "utils/CommonIncludes.hpp"
#include "utils/SharedResources.hpp"
#include "utils/Settings.hpp"
#include "states/StateSwitcher.hpp"
#include "objects/CursorObject.hpp"
#include "managers/InputManager.hpp"

namespace Input {
GLvoid keyboardPress(GLFWwindow *t_window, GLint t_key, GLint t_scanCode, GLint t_action, GLint t_mods);
GLvoid mousePress(GLFWwindow *t_window, GLint t_key, GLint t_action, GLint t_mods);
GLvoid mousePosition(GLFWwindow *t_window, GLdouble t_posX, GLdouble t_posY);
}

int main(int argc, char const *argv[]) {

// Create window and set witch OpenGL version we use.  
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

SharedResources::window = glfwCreateWindow(Settings::windowWidth, Settings::windowHeight, Settings::windowName, NULL, NULL);
glfwMakeContextCurrent(SharedResources::window);    

// Callback function.
glfwSetCursorPosCallback(SharedResources::window, Input::mousePosition);
glfwSetMouseButtonCallback(SharedResources::window, Input::mousePress);
glfwSetKeyCallback(SharedResources::window, Input::keyboardPress);
// Load OpenGL functions.
gladLoadGLLoader(GLADloadproc(glfwGetProcAddress));
glViewport(0, 0, Settings::windowWidth, Settings::windowHeight);

// Blending functions.
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// Init singleton classes
InputManager::initInputManager();
StateSwitcher::init();

// Game loop.
GLfloat lastFrame = 0.0f;
while (!glfwWindowShouldClose(SharedResources::window)) {

    glfwPollEvents();

    GLfloat currentFrame = glfwGetTime();
    SharedResources::deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    StateSwitcher::selectedStateBackground();
    StateSwitcher::selectedStateLogic();
    StateSwitcher::selectedStateRender();
    
    glfwSwapBuffers(SharedResources::window);

    glfwPollEvents();
}
// Terminate window.
glfwTerminate(); 
return 0;
}

namespace Input {
GLvoid keyboardPress(GLFWwindow *t_window, GLint t_key, GLint t_scanCode, GLint t_action, GLint t_mods) {
    InputManager::getKeyboardKeys()[t_key] = t_action;
}
GLvoid mousePress(GLFWwindow *t_window, int t_key, int t_action, int t_mods) {
    InputManager::getMouseKeys()[t_key] = t_action;
}
GLvoid mousePosition(GLFWwindow *t_window, double t_posX, double t_posY) {
    InputManager::getMousePosition() = glm::vec2(float(t_posX), float(t_posY));
}

}