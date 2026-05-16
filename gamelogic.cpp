
#include "gamelogic.hpp"

gamelogic::gamelogic() {
    current_player = 1;
    phase = prep;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            p1_board[i][j] = L_empty;
            p2_board[i][j] = L_empty;
        }
    }
}

logicstate gamelogic::get_p1_cell(int x, int y) const {
    return p1_board[x][y];
}
logicstate gamelogic::get_p2_cell(int x, int y) const {
    return p2_board[x][y];
}

gamephase gamelogic::get_phase() const {
    return phase;
}

void gamelogic::handel_click_p1(int x, int y) {
    if (phase == prep) {
        if(p1_board[x][y] == L_empty) {
            p1_board[x][y] = L_ship;
        }else if(p2_board[x][y] == L_ship) {
            p1_board[x][y] = L_empty;
        }
    }
}
void gamelogic::handel_click_p2(int x, int y) {

}