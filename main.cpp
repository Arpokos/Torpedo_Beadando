#include "graphics.hpp"
#include "application.hpp"
#include "button.hpp"
#include "label.hpp"
#include "listbox.hpp"
#include "widget.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace genv;

int main()
{
    gout.open(800, 600);
    gout.set_title("Torpedo Teszt");

    Application app;

    app.register_widget(new Label(50, 50, 300, 30, "Torpedo - Widget Teszt"));

    std::vector<std::string> fegyverek = {"Sima loves", "Szonyegbombazas", "Kereszt-loves", "Radar"};
    app.register_widget(new ListBox(50, 100, 200, 150, fegyverek));

    app.register_widget(new Button(50, 280, 200, 40, "Teszt Gomb", []() {
        std::cout << "A gomb tokeletesen mukodik!" << std::endl;
    }));

    app.event_loop();

    return 0;
}