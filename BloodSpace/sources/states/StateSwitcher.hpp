/*
    StateSwticher.hpp
    Purpose: State switcher.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#ifndef STATE_SWITCHER_HPP
#define STATE_SWITCHER_HPP

#include "../utils/CommonIncludes.hpp"
#include "../states/BaseState.hpp"

class StateSwitcher {
    private:
        StateSwitcher();
    public:
        static StateSwitcher &init();
        static GLvoid selectedStateBackground();
        static GLvoid selectedStateLogic();
        static GLvoid selectedStateRender();
};

#endif //STATE_SWITCHER_HPP