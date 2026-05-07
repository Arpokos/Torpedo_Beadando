#include "button.hpp"

using namespace genv;

Button::Button(int x, int y, int sx, int sy, std::string text, std::function<void()> action)
    : Widget(x, y, sx, sy), text(text), action(action) {}

void Button::draw() const {
    gout << move_to(x, y) << color(100, 100, 100) << box(size_x, size_y);
    gout << move_to(x + 2, y + 2) << color(150, 150, 150) << box(size_x - 4, size_y - 4);

    int text_w = gout.twidth(text);
    gout << move_to(x + (size_x - text_w) / 2, y + size_y / 2 + gout.cascent() / 2 - 2)
         << color(255, 255, 255) << genv::text(text);
}

void Button::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y)) {
        if (action) action();
    }
}