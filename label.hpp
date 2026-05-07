#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include "widget.hpp"
#include <string>

class Label : public Widget {
    std::string text;
public:
    Label(int x, int y, int sx, int sy, std::string text);
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    void set_text(std::string t) { text = t; }
};

#endif