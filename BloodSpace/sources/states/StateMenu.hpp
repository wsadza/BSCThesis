/*
    StateLogo.hpp
    Purpose: -

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP

#include "../utils/CommonIncludes.hpp"
#include "../states/BaseState.hpp"
#include "../widgets/ButtonWidget.hpp"
#include "../generators/ParticleGenerator.hpp"
#include "../generators/ObjectGenerator.hpp"

class StateMenu :public BaseState {
private:
    std::vector<WidgetButton>            m_widgets;
    ObjectGenerator<CreatureObject>     *m_objectGenerator;
    ParticleGenerator                   *m_particleGenerator;
public:
  StateMenu();
  GLvoid stateLogic();
  GLvoid stateRender();
  GLvoid stateBackground();
};

#endif // STATE_MENU_HPP