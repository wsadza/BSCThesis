/*
    StatePlay.hpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef STATE_PLAY_HPP
#define STATE_PLAY_HPP

#include "../utils/CommonIncludes.hpp"
#include "../states/BaseState.hpp"
#include "../objects/PlayerObject.hpp"
#include "../objects/CursorObject.hpp"
#include "../objects/CreatureObject.hpp"
#include "../generators/ObjectGenerator.hpp"

class StatePlay :public BaseState {
private:
  PlayerObject *m_playerObject;
  ObjectGenerator<CreatureObject> *m_objectGenerator;
  ParticleGenerator *m_particleGenerator;
public:
  StatePlay();
  GLvoid stateLogic();
  GLvoid stateRender();
  GLvoid stateBackground();
};

#endif // STATE_PLAY_HPP