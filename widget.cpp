#include "widget.hpp"

Widget::Widget(int x, int y, int sx, int sy) : x(x), y(y), size_x(sx), size_y(sy) {}

bool Widget::is_selected(int mouse_x, int mouse_y) const {
    return mouse_x >= x && mouse_x <= x + size_x && mouse_y >= y && mouse_y <= y + size_y;
}