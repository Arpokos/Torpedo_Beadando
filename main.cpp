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

    Grid* player_board = new Grid(50,50,30,[player_board](int x,int y){
        std:: cout << "press"<< x << "," << y << std::endl;
    player_board->set_field_state(x,y,ship);
    });
    app.register_widget(player_board);

    app.event_loop();

    return 0;
}