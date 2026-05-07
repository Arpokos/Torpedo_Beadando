#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>
#include "widget.hpp"

class Application {
protected:
    std::vector<Widget*> widgets;
public:
    Application();
    virtual ~Application();
    void register_widget(Widget* w);
    void event_loop();
};

#endif