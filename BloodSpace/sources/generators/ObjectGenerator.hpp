/*
    ObjectGenerator.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19 
*/
#ifndef OBJECT_GENERATOR_HPP
#define OBJECT_GENERATOR_HPP

#include "../utils/CommonIncludes.hpp"

template<class Type>
class ObjectGenerator {
private:
    std::vector<Type>   m_objects;
    GLuint              m_objectAmount;
    glm::vec2           m_spawnPoint;
    GLfloat             m_currentDuration;
    GLfloat             m_duration;
    GLboolean           m_finish;
    glm::vec2 startingPosition();
public:
    ObjectGenerator(GLuint t_objectAmount, glm::vec2 t_spawnPoint = glm::vec2(0.0f));
    GLvoid generateObject(GLfloat t_durationTime = 1.0f);
    GLvoid generatedObjectLogic();
    GLvoid generatedObjectRender();

    std::vector<Type> &getObjects();
};//ObjectGenerator

#include "../generators/ObjectGenerator.hxx"

#endif //OBJECT_GENERATOR_HPP
