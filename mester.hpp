#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include "widget.hpp"
#include "grid.hpp"
#include "gamelogic.hpp"
#include "label.hpp"
#include "button.hpp"
#include "listbox.hpp"
#include <vector>
#include <string>

class mester : public Widget {
    gamelogic logic;

    Grid*     p1_grid;
    Grid*     p2_grid;
    Label*    p1_label;
    Label*    p2_label;
    Label*    status_label;
    Label*    dir_label;
    Button*   rotate_btn;
    Button*   start_btn;
    Button*   new_game_btn;
    ListBox*  size_list;

public:
    mester(int x, int y, int sx, int sy);
    ~mester();

    void draw()   const override;
    void handle(genv::event ev) override;

private:
    void sync_grids();
    void on_p1_click(int x, int y);
    void on_p2_click(int x, int y);
    void new_game();
};

#endif