/*
    ParticleGenerator.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19 
*/
#ifndef PARTICLE_GENERATOR_HPP
#define PARTICLE_GENERATOR_HPP

#include "../utils/CommonIncludes.hpp"
#include "../pieces/Primitive.hpp"
#include "../pieces/Image.hpp"
#include "../pieces/Shader.hpp"

class ParticleGenerator {
    private:
        struct Particle : public Primitive {
            private:
                GLfloat m_velocity;
                GLfloat m_life;
            public:
                Particle();

                GLvoid setVelocity(GLfloat t_velocity);
                GLvoid setLife(GLfloat t_life);

                GLfloat getVelocity();
                GLfloat &getLife();
        }; // Particle

        Image           *m_image;
        Shader          *m_shader;
        
        glm::vec2       m_particleSize;

        glm::vec2       *m_scopePosition;
        glm::vec2       m_scopeSize;
        glm::vec3       m_scopeColor;

        glm::vec3       m_drains;

        GLboolean       m_blending;
        GLboolean       m_scaling;

        std::vector<Particle> m_particles;

        GLvoid randomiseParticle();
        GLvoid updateParticle();
    public:
        ParticleGenerator(const std::string &t_shaderPath, GLuint t_particlesAmount = 500, GLboolean t_blending = true);
        GLvoid setImage(const std::string& t_imagePath);
        GLvoid setImage(Image &t_image);
        GLvoid setScopeColor(GLfloat t_x, GLfloat t_y, GLfloat t_z);
        GLvoid setParticleSize(GLfloat t_x, GLfloat t_y, GLboolean t_scale = true);
        GLvoid setSpawnPointRange(GLfloat t_x, GLfloat t_y, GLfloat t_z, GLfloat t_w);
        GLvoid setSpawnPointRange(glm::vec2 &t_objectPosition, glm::vec2 t_obectSize = glm::vec2(5.0f));
        GLvoid setDrains(GLfloat t_lifeDrain, GLfloat t_colorDrain, GLfloat t_positionDrain);

        GLvoid render();

}; //ParticleGenerator

#endif //PARTICLE_GENERATOR_HPP