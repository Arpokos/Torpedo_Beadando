#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widget.hpp"
#include <string>
#include <functional>

class Button : public Widget {
    std::string text;
    std::function<void()> action;
public:
    Button(int x, int y, int sx, int sy, std::string text, std::function<void()> action);
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
};

#endif