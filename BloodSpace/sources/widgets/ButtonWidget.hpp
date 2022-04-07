/*
    WidgetButton.hpp
    Purpose: Widget button

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#ifndef WIDGET_BUTTON_HPP
#define WIDGET_BUTTON_HPP

#include "../utils/CommonIncludes.hpp"
#include "../widgets/BaseWidget.hpp"
#include "../effects/Dash.hpp"

class WidgetButton : public Widget {
    private:
        GLvoid checkClick();
        GLboolean widgetCollision();
        std::string     m_nextState;
        Dash            *m_dash;
        GLboolean       m_clicked;
    public:
        WidgetButton(const std::string &t_sourceForInitialization);
        GLvoid widgetLogic();
        GLvoid widgetRender();
        std::string getNextState();
        GLboolean clicked();
        Dash            *m_textDash;
};

#endif //WIDGET_BUTTON_HPP