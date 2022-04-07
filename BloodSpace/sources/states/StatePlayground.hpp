/*
    StatePlayground.hpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef STATE_PLAYGROUND_HPP
#define STATE_PLAYGROUND_HPP

#include "../utils/CommonIncludes.hpp"
#include "../states/BaseState.hpp"

class StatePlayground :public BaseState {
private:
public:
  StatePlayground();
  GLvoid stateLogic();
  GLvoid stateBackground();
  GLvoid stateRender();
};

#endif // STATE_PALYGROUND_HPP