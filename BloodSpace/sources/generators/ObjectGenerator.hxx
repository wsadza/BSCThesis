/*
    ObjectGenerator.hxx
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 08/03/19 
*/
#include "../generators/ObjectGenerator.hpp"
#include "../objects/CreatureObject.hpp"
#include "../utils/SharedResources.hpp"

template<class Type>
ObjectGenerator<Type>::ObjectGenerator(GLuint t_objectAmount, glm::vec2 t_spawnPoint)
    : m_objectAmount(t_objectAmount)
    , m_spawnPoint(t_spawnPoint)
    , m_currentDuration(0.0f)
    , m_finish(false) {

    if (m_spawnPoint == glm::vec2(0.0f)) {
        m_spawnPoint = startingPosition();
    }
}

template<class Type>
GLvoid ObjectGenerator<Type>::generateObject(GLfloat t_durationTime) {

     if((m_currentDuration += SharedResources::deltaTime) >= t_durationTime) {
        if (m_objects.size() < m_objectAmount && !m_finish) {
            Type type;
            type.getPrimitive().setPosition(m_spawnPoint);
            m_objects.push_back(type);
            m_currentDuration = 0.0f;
        } else {
            m_finish = true;
        }
     }
 }

template<class Type>
GLvoid ObjectGenerator<Type>::generatedObjectLogic() {
    for (auto& ite: m_objects) {
       ite.objectLogic();
    }
}

template<class Type>
GLvoid ObjectGenerator<Type>::generatedObjectRender() {
    for (auto& ite: m_objects) {
       ite.objectRender();
    }
}

template<class Type>
glm::vec2 ObjectGenerator<Type>::startingPosition() {
    srand (time(NULL));
    GLuint rand_C = rand() % 100;
    GLfloat rand_x = rand() % GLuint(Settings::windowWidth) + rand_C;
    GLfloat rand_y = (rand() % 10);
    return glm::vec2(rand_x, -rand_y);   
}

template<class Type>
std::vector<Type> &ObjectGenerator<Type>::getObjects() {
    return m_objects;
}
