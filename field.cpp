
#include "field.hpp"
using namespace genv;

field::field(int x, int y, int size, int f_x, int f_y, std::function<void(int, int)> action)
    :Widget(x, y, size, size), field_x(f_x), field_y(f_y), field_state(empty),on_click(action)
{
}

void field::draw() const {
    gout << move_to(x, y) << color(0,0,0) << box(size_x,size_y);
    gout << move_to(x+1,y+1) << color(30,144,255) << box(size_x-2,size_y-2);
    if (field_state == ship) {
        gout << move_to(x +4,y+4) << color(100,100,100) << box(size_x-8,size_y-8);

    }
    if (field_state == hit) {
        gout << move_to(x+4,y+4)<< color(255,0,0) << line(size_x-8,size_y-8);
        gout << move_to(x + size_x - 4, y + 4) << color(255, 0, 0) << line(-size_x + 8, size_y - 8);
    }
    else if (field_state == miss) {
        gout << move_to(x + size_x/2 -2,y + size_y/2 -2) << color(255,255,255) << box(4,4);
    }

}
void field::handle(genv::event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y)) {
        if (on_click) {
            on_click(field_x, field_y);
        }
    }
}
void field::set_state(field_type new_state) {
    field_state = new_state;
}