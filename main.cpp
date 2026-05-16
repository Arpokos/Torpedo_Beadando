#include "graphics.hpp"
#include "application.hpp"
#include "button.hpp"
#include "label.hpp"
#include "listbox.hpp"
#include "widget.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "field.hpp"
#include "grid.hpp"
#include "gamelogic.hpp"
using namespace genv;

void sync_grids(const gamelogic& logic,Grid* p1_grid,Grid* p2_grid) {
    for (int x = 0; x <10; ++x) {
        for (int y = 0; y <10; ++y) {
            logicstate l1 = logic.get_p1_cell(x,y);
            if (l1 == L_ship) {
                p1_grid->set_field_state(x,y,ship);
            }
            else if (l1 == L_hit) {
                p1_grid->set_field_state(x,y,hit);
            }
            else if (l1 == L_miss) {
                p1_grid->set_field_state(x,y,miss);
            }
            else {
                p1_grid->set_field_state(x,y,empty);
            }
            logicstate l2 = logic.get_p2_cell(x,y);
            if (l2 == L_hit) {
                p2_grid->set_field_state(x,y,hit);
            }
            else if (l2 == L_miss) {
                p2_grid->set_field_state(x,y,miss);
            }
            else {
                p2_grid->set_field_state(x,y,empty);
            }
        }
    }
}


int main() {
    gout.open(800, 600);
    gout.set_title("Torpedo");

    Application app;
    /*
    app.register_widget(new Label(50, 50, 300, 30, "Torpedo - Widget Teszt"));

    std::vector<std::string> fegyverek = {"Sima loves", "Szonyegbombazas", "Kereszt-loves", "Radar"};
    app.register_widget(new ListBox(50, 100, 200, 150, fegyverek));

    app.register_widget(new Button(50, 280, 200, 40, "Teszt Gomb", []() {
        std::cout << "A gomb tokeletesen mukodik!" << std::endl;
    }));*/


    /*----------------
     field* test_field = new field(300,200,40,0,0,[test_field](int fx,int fy) {
        std :: cout << "press" << fx << ", "<< fy << std::endl;
        test_field->set_state(hit);
    });
    app.register_widget(test_field);
    -------------*/

    /*---------------------
    Grid* player_board = new Grid(50,50,30,[player_board](int x,int y){
        std:: cout << "press"<< x << "," << y << std::endl;
    player_board->set_field_state(x,y,ship);
    });
    app.register_widget(player_board);
    ------------------*/
    gamelogic logic;
    Button*rotate_btn = new Button(50,400,200,50,"rotate", [&logic]() {
    logic.toggle_direction();
});
    std::vector<std::string> ships={"S(1)","S(2)","S(3)","S(4)"};
    ListBox* size_list = new ListBox(50,480,200,100,ships);

    Grid* p1_grid = nullptr;
    Grid* p2_grid = nullptr;
    p1_grid = new Grid(50,50,30,[&](int x,int y){
        if (logic.get_phase()== prep) {
            int sel_idx = size_list->get_selected_index();
            if (sel_idx >= 0) {
            logic.set_ship_size(sel_idx+1);
            }
        }
        logic.handel_click_p1(x,y);
        sync_grids(logic,p1_grid,p2_grid);
    });
    p2_grid = new Grid(450,50,30,[&](int x,int y) {
        if (logic.check_winner() == 0) {
            logic.handel_click_p2(x,y);
            sync_grids(logic,p1_grid,p2_grid);
            int winner = logic.check_winner();
            if (winner == 1) {
                std::cout<<"Enemy fleet eliminated. You win!"<<std::endl;
            }
            else if (winner == 2) {
                std::cout<<"Your fleet has been destroyed! Game Over."<<std::endl;
            }
        }

    });
    Button* start_btn = new Button(300,550,200,50,"start", [&]() {
        logic.start_shooting_phase();
        std::cout<<"game started"<<std::endl;
    });
    app.register_widget(p1_grid);
    app.register_widget(p2_grid);
    app.register_widget(start_btn);
    app.register_widget(size_list);
    app.register_widget(rotate_btn);

    app.event_loop();

    return 0;
}