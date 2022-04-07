/*
    WidgetLabel.hpp
    Purpose: Widget label

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#ifndef WIDGET_LABEL_HPP
#define WIDGET_LABEL_HPP

#include "../utils/CommonIncludes.hpp"
#include "../widgets/BaseWidget.hpp"
#include "../effects/Dash.hpp"

class WidgetButton : public Widget {
    private:
        Dash            *m_dash;
        GLboolean        m_clicked;
        std::string      m_nextState;
        
        GLvoid          checkClick();
        GLboolean       widgetCollision();

    public:
        WidgetButton(const std::string &t_sourceForInitialization);
        GLvoid widgetLogic();
        GLvoid widgetRender();
        std::string getNextState();
        GLboolean clicked();
        Dash *m_textDash;
};

#endif //WIDGET_BUTTON_HPP