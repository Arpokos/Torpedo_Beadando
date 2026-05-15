#include "grid.hpp"

Grid::Grid(int x, int y, int cell_size, std::function<void(int, int)> action)
    : Widget(x, y, cell_size*10, cell_size*10), on_grid_click(action)
{
    fields.resize(10, std::vector<field*>(10, nullptr));
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            fields[i][j] = new field(
                x + i*cell_size,
                y + j*cell_size,
                cell_size,
                i,j,
                on_grid_click
                );
        }
    }
}
Grid::~Grid() {
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            delete fields[i][j];
        }
    }
}

void Grid::draw() const {
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            fields[i][j]->draw();
        }
    }
}

void Grid::handle(genv::event ev) {
    if (ev.type == genv::ev_mouse && ev.button == genv::btn_left) {
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                if (fields[i][j]->is_selected(ev.pos_x, ev.pos_y)) {
                    fields[i][j]->handle(ev);
                    return;
                }
            }
        }
    }
}

void Grid::set_field_state(int f_x, int f_y, field_type state) {
    if (f_x>=0 && f_x<10 && f_y>=0 && f_y<10) {
        fields[f_x][f_y]->set_state(state);
    }
}
