/*
    StateLogo.hpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef STATE_LOGO_HPP
#define STATE_LOGO_HPP

#include "../utils/CommonIncludes.hpp"
#include "../states/BaseState.hpp"
#include "../objects/ObjectLogo.hpp"
#include "../effects/Dash.hpp"

class StateLogo :public BaseState {
private:
    ObjectLogo    *m_logo;
public:
  StateLogo();
  GLvoid stateLogic();
  GLvoid stateRender();
  GLvoid stateBackground();
};

#endif // STATE_LOGO_HPP