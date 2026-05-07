#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int x, y, size_x, size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual ~Widget() {}
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif