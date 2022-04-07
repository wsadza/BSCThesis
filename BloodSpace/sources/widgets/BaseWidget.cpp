/*
    Widget.hpp
    Purpose: Widget class

    @author Igor Sadza
    @version 0.1 - 10/03/19
*/
#include "../widgets/BaseWidget.hpp"

Widget::Widget() {
    m_widgetObject = new BaseObject();
    m_blockInput = true;
}

BaseObject &Widget::getWidgetObject() {
    return *m_widgetObject;
}

GLboolean &Widget::blockInput() {
    return m_blockInput;
}