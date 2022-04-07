/*
    Widget.hpp
    Purpose: Widget class

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "../utils/CommonIncludes.hpp"
#include "../objects/BaseObject.hpp"

class Widget {
    private:
        BaseObject *m_widgetObject;
        GLboolean m_blockInput;
    public:
        Widget();
        virtual GLvoid widgetLogic() = 0;
        virtual GLvoid widgetRender() = 0;
        BaseObject &getWidgetObject();
        GLboolean &blockInput();
};

#endif //WIDGET_HPP