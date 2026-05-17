#include "graphics.hpp"
#include "application.hpp"
#include "mester.hpp"
using namespace genv;

int main() {
    gout.open(800,600);
    gout.set_title("Torpedo");
    Application app;
    app.register_widget(new mester(0,0,800,600));
    app.event_loop();
    return 0;
}