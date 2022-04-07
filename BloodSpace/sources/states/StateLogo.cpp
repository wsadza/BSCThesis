/*
    StateLogo.cpp
    Purpose: State playground for testing.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/

#include "../states/StateLogo.hpp"
#include "../objects/BaseObject.hpp"
#include "../objects/PlayerObject.hpp"

static StateLogo *stateLogo;

StateLogo::StateLogo() {
  stateLogo = this;
  BaseState::Register("StateLogo", stateLogo);
  BaseState::setInstance("StateLogo");

  m_logo = new ObjectLogo();
}

GLvoid StateLogo::stateBackground() {

}

GLvoid StateLogo::stateLogic() {
  m_logo->objectLogic();
}

GLvoid StateLogo::stateRender() { 
m_logo->objectRender();
}