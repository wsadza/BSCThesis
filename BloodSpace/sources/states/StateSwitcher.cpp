/*
    StateSwticher.cpp
    Purpose: State switcher.

    @author Igor Sadza
    @version 0.1 - 07/03/19
*/
#include "../states/StateSwitcher.hpp"
#include "../states/StatePlayground.hpp"
#include "../renderers/TextRenderer.hpp"
#include "../renderers/PrimitiveRenderer.hpp"
#include "../objects/CursorObject.hpp"
#include "../states/StateLogo.hpp"
#include "../states/StateMenu.hpp"
#include "../states/StatePlay.hpp"

StateSwitcher::StateSwitcher() {
    TextRenderer::initRenderer();
    PrimitiveRenderer::initRenderer();
    CursorObject::initCursor("resources/sprites/cursors/cursor_0/cursor_normal.png");

    StateLogo *stateLogo = new StateLogo();
}

StateSwitcher &StateSwitcher::init() {
    static StateSwitcher stateSwitcher;
    return stateSwitcher;
}

GLvoid StateSwitcher::selectedStateBackground() {
    BaseState::GetInstance()->stateBackground();
}

GLvoid StateSwitcher::selectedStateLogic() {
    BaseState::GetInstance()->stateLogic();
}

GLvoid StateSwitcher::selectedStateRender() {
    BaseState::GetInstance()->stateRender();
}