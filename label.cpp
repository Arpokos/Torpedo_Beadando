#include "label.hpp"

using namespace genv;

Label::Label(int x, int y, int sx, int sy, std::string text)
    : Widget(x, y, sx, sy), text(text) {}

void Label::draw() const {
    gout << move_to(x, y + gout.cascent()) << color(255, 255, 255) << genv::text(text);
}

void Label::handle(genv::event ev) {}