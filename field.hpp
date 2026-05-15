
#ifndef CLIONGRAPHICSKIT_FIELD_HPP
#define CLIONGRAPHICSKIT_FIELD_HPP
#include "widget.hpp"
#include "functional"
enum field_type {empty,ship,hit,miss};
class field : public Widget{
    protected:
    int field_x,field_y;
    field_type field_state;
    std ::function<void(int,int)> on_click;
    public:
    field(int x, int y, int size, int f_x, int f_y, std::function<void(int,int)>action);
    virtual void draw() const override;
    virtual void handle(genv::event ev) override;
    void set_state(field_type new_state);

};


#endif //CLIONGRAPHICSKIT_FIELD_HPP