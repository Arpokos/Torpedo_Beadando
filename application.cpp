#include "application.hpp"

using namespace genv;

Application::Application() {}

Application::~Application() {
    for (Widget* w : widgets) delete w;
}

void Application::register_widget(Widget* w) {
    widgets.push_back(w);
}

void Application::event_loop() {
    event ev;
    Widget* focus = nullptr;
    while(gin >> ev && ev.keycode != key_escape) {
        /*if (ev.type == ev_mouse && ev.button == btn_left) {
            focus = nullptr;
            for (Widget* w : widgets) {
                if (w->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = w;
                }
            }
        }*/
        for (Widget* w : widgets) {
            w->handle(ev);
        }

        /*if (focus) {
            focus->handle(ev);
        }
        */
        gout << move_to(0,0) << color(30, 30, 30) << box(800, 600);
        for (Widget* w : widgets) w->draw();
        gout << refresh;
    }
}