/*
    ParticleGenerator.cpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19 
*/
#include "../generators/ParticleGenerator.hpp"
#include "../renderers/PrimitiveRenderer.hpp"
#include "../utils/SharedResources.hpp"
#include "../utils/Settings.hpp"

// ! ParticleGenerator class

ParticleGenerator::ParticleGenerator(const std::string &t_shaderPath, 
                                     GLuint t_particlesAmount, 
                                     GLboolean t_blending)
                                     : m_blending(t_blending)
                                     , m_scaling(false)
                                     , m_image(nullptr) {

    m_shader = new Shader(t_shaderPath);

    for(int i = 0; i < t_particlesAmount; i++) {
        Particle particle;
        m_particles.push_back(particle);
    }
}

GLvoid ParticleGenerator::randomiseParticle() {

    for (auto& ite: m_particles) {

        if (ite.getColor().w <= 0.0f 
        || glm::any(glm::greaterThanEqual(ite.getPosition(), glm::vec2(Settings::windowWidth, Settings::windowHeight)))
        || ite.getLife() <= 0.0f) {

            if (ite.getColor().w <= 0.0f) {
                ite.getColor().w = 1.0f;
            }

            for (int i = 0; i < 3; i++) {
                (m_scopeColor[i] == 1.0f)
                ? ite.getColor()[i] = 0.5 + ((rand() % 100) / 100.0f)    
                : ite.getColor()[i] = ((rand() % 30) / 100.0f); 
            }

          glm::vec2 tmp = *m_scopePosition;
          for (int i = 0; i < 2; i++) {
            if (m_scopeSize[i] > 0.0f || tmp[i] > 0.0f) {
              ite.getPosition()[i] = rand() % (GLuint)m_scopeSize[i] + tmp[i];
            } else if (m_scopeSize[i] < 0.0f || tmp[i] < 0.0f){
              ite.getPosition()[i] = -(rand() % (GLuint)m_scopeSize[i] + (-tmp[i]));
            }
          }

          ite.setSize(m_particleSize * ((rand() % 100) / 100.0f));
          ite.setVelocity((0.3 + ((rand() % 100) / 100.0f)));
          ite.setLife(1.0f);            
        }

    }
}
GLvoid ParticleGenerator::updateParticle() {
    for (auto& ite:m_particles) {
        ite.getPosition().y += m_drains.z * ite.getVelocity() * SharedResources::deltaTime;
        ite.getColor().w -= m_drains.y * ite.getVelocity() * SharedResources::deltaTime;
        ite.getLife() -= m_drains.x * ite.getVelocity() * SharedResources::deltaTime;      
    }
}
GLvoid ParticleGenerator::render() {
    
    randomiseParticle();
    updateParticle();

    m_shader->use();

    if (m_image) {
        m_image->use();        
    }

    if(m_blending) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);       
    }

    for (auto& ite: m_particles) {

        glm::mat4 modelMatrix;
        modelMatrix = glm::translate(modelMatrix, glm::vec3(ite.getPosition(), 0.0f));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(ite.getSize(), 0.0f));

        m_shader->sendVariable("t_model", modelMatrix);
        m_shader->sendVariable("t_color", ite.getColor());

        PrimitiveRenderer::renderPrimitive();   
    }

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);    
}

// ! Setter

GLvoid ParticleGenerator::setImage(const std::string& t_imagePath) {
    m_image = new Image(t_imagePath);
    m_particleSize = m_image->getSize();
}
GLvoid ParticleGenerator::setImage(Image &t_image){
    m_image = &t_image;
    m_particleSize = m_image->getSize();
}
GLvoid ParticleGenerator::setScopeColor(GLfloat t_x, GLfloat t_y, GLfloat t_z){
    m_scopeColor = glm::vec3(t_x, t_y, t_z);
}
GLvoid ParticleGenerator::setParticleSize(GLfloat t_x, GLfloat t_y, GLboolean t_scale){
    m_particleSize = glm::vec2(t_x, t_y);
    m_scaling = t_scale;
}
GLvoid ParticleGenerator::setSpawnPointRange(GLfloat t_x, GLfloat t_y, GLfloat t_z, GLfloat t_w) {
    m_scopePosition = new glm::vec2();
    *m_scopePosition = glm::vec2(t_x, t_y);
    m_scopeSize = glm::vec2(t_z, t_w);
}
GLvoid ParticleGenerator::setSpawnPointRange(glm::vec2 &t_objectPosition, glm::vec2 t_obectSize){
    m_scopePosition = &t_objectPosition;
    m_scopeSize = t_obectSize;
}
GLvoid ParticleGenerator::setDrains(GLfloat t_lifeDrain, GLfloat t_colorDrain, GLfloat t_positionDrain){
    m_drains.x = t_lifeDrain;
    m_drains.y = t_colorDrain;
    m_drains.z = t_positionDrain;
}

// ! ParticleGenerator::Particle struct.

ParticleGenerator::Particle::Particle() : Primitive(), m_life(0.0f), m_velocity(1.0f) {

}

// ! ParticleGenerator::Particle setters.

GLvoid ParticleGenerator::Particle::setVelocity(GLfloat t_velocity) {
    m_velocity = t_velocity;
}
GLvoid ParticleGenerator::Particle::setLife(GLfloat t_life) {
    m_life = t_life;
}

// ! ParticleGenerator::Particle getters.

GLfloat ParticleGenerator::Particle::getVelocity() {
    return m_velocity;
}
GLfloat &ParticleGenerator::Particle::getLife() {
    return m_life;
}