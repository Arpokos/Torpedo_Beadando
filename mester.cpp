#include "mester.hpp"
#include "graphics.hpp"
#include <cstdlib>
#include <ctime>

using namespace genv;
mester::mester(int x, int y, int sx, int sy)
    : Widget(x, y, sx, sy)
{
    srand(time(nullptr));


    p1_label     = new Label(50,  20, 300, 25, "My board");
    p2_label     = new Label(450, 20, 300, 25, "Enemy board");
    status_label = new Label(250, 555, 350, 25, "Ship placement");
    dir_label    = new Label(50,  415, 200, 25, "Rotate");


    std::vector<std::string> ships = {"1", "2", "3", "4"};
    size_list = new ListBox(50, 440, 150, 80, ships);


    rotate_btn = new Button(210, 440, 130, 35, "Rotate", [this]() {
        logic.toggle_direction();
    });

    start_btn = new Button(250, 510, 150, 35, "Game start", [this]() {
        if (logic.get_phase() == prep) {
            logic.start_shooting_phase();
            status_label->set_text("Locate enemy ships");
        }
    });


    new_game_btn = new Button(620, 510, 130, 35, "New game", [this]() {
        new_game();
    });

    p1_grid = new Grid(50, 45, 30, [this](int x, int y) {
        on_p1_click(x, y);
    });

    p2_grid = new Grid(450, 45, 30, [this](int x, int y) {
        on_p2_click(x, y);
    });
}

mester::~mester() {
    delete p1_grid;
    delete p2_grid;
    delete p1_label;
    delete p2_label;
    delete status_label;
    delete dir_label;
    delete rotate_btn;
    delete start_btn;
    delete new_game_btn;
    delete size_list;
}

void mester::draw() const {
    gout << move_to(x, y) << color(30, 30, 30) << box(size_x, size_y);

    p1_label->draw();
    p2_label->draw();
    status_label->draw();
    dir_label->draw();
    size_list->draw();
    rotate_btn->draw();
    start_btn->draw();
    new_game_btn->draw();
    p1_grid->draw();
    p2_grid->draw();
}

void mester::handle(genv::event ev) {
    rotate_btn->handle(ev);
    start_btn->handle(ev);
    new_game_btn->handle(ev);
    size_list->handle(ev);
    p1_grid->handle(ev);
    p2_grid->handle(ev);
}


void mester::sync_grids() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            logicstate l1 = logic.get_p1_cell(x, y);
            if(l1 == L_ship) {
             p1_grid->set_field_state(x, y, ship);
            }
            else if (l1 == L_hit) {
             p1_grid->set_field_state(x, y, hit);
            }
            else if (l1 == L_miss) {
             p1_grid->set_field_state(x, y, miss);
            }
            else {
                p1_grid->set_field_state(x, y, empty);
            }


            logicstate l2 = logic.get_p2_cell(x, y);
            if(l2 == L_hit) {
               p2_grid->set_field_state(x, y, hit);
            }
            else if (l2 == L_miss) {
                p2_grid->set_field_state(x, y, miss);
            }
            else {
                p2_grid->set_field_state(x, y, empty);
            }
        }
    }
}

void mester::on_p1_click(int x, int y) {
    if (logic.get_phase() != prep) {
        return;
    }

    int sel = size_list->get_selected_index();
    if (sel >= 0) {
      logic.set_ship_size(sel + 1);
    }

    logic.handel_click_p1(x, y);
    sync_grids();
}

void mester::on_p2_click(int x, int y) {
    if (logic.get_phase() != shooting) {
        return;
    }
    if (logic.check_winner() != 0) {
        return;
    }

    logic.handel_click_p2(x, y);
    sync_grids();

    int winner = logic.check_winner();
    if      (winner == 1) {
    status_label->set_text("Enemy fleet eliminated. You win!");
    }
    else if (winner == 2) {
     status_label->set_text("Your fleet has been destroyed! Game Over.");
    }
}

void mester::new_game() {

    logic = gamelogic();
    dir_label->set_text("Rotate");
    status_label->set_text("Ship placement");
    sync_grids();
}