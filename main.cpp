#include "graphics.hpp"
#include "application.hpp"
#include "button.hpp"
#include "label.hpp"
#include "listbox.hpp"
#include "widget.hpp"
#include <iostream>
#include <vector>
#include <string>

#include "field.hpp"
#include "grid.hpp"
#include "gamelogic.hpp"
using namespace genv;

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
    Grid* p1_grid = nullptr;
    p1_grid = new Grid(50,50,30,[&](int x,int y){
        logic.handel_click_p1(x,y);
        logicstate l_state = logic.get_p1_cell(x,y);
        field_type f_state = empty;
        if (l_state == L_ship) {
            f_state = ship;
        }
        else if (l_state == L_hit) {
            f_state = hit;
        }
        else if (l_state == L_miss) {
            f_state = miss;
        }
        p1_grid->set_field_state(x,y,f_state);
    });
    app.register_widget(p1_grid);

    app.event_loop();

    return 0;
}