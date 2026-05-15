
#ifndef CLIONGRAPHICSKIT_GRID_HPP
#define CLIONGRAPHICSKIT_GRID_HPP
#include "widget.hpp"
#include "field.hpp"
#include "vector"
#include "functional"

class Grid : public Widget{
    protected:
    std::vector<std::vector<field*>> fields;
    std::function<void(int,int)> on_grid_click;
    public:
    Grid(int x,int y, int cell_size, std::function<void(int,int)> action);
    virtual ~Grid();
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    void set_field_state(int f_x, int f_y, field_type state);

};


#endif //CLIONGRAPHICSKIT_GRID_HPP