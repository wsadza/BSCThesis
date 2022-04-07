/*
    ObjectShot.hpp
    Purpose: - 

    @author Igor Sadza
    @version 0.1 - 14/03/19
*/
#ifndef OBJECT_SHOT_HPP
#define OBJECT_SHOT_HPP

#include "sources/utils/CommonIncludes.hpp"
#include "sources/objects/BaseObject.hpp"
#include "sources/generators/ParticleGenerator.hpp"

class ObjectShot : public BaseObject {
    private:
        std::vector<BaseObject> m_shots;
        ParticleGenerator *m_particleGenerator;
    public:
        ObjectShot(glm::vec2 t_startingPosition);
        GLvoid shotLogic();
};

#endif //OBJECT_SHOT_HPP

