
#include "gamelogic.hpp"
#include "cstdlib"
gamelogic::gamelogic() {
    current_player = 1;
    phase = prep;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            p1_board[i][j] = L_empty;
            p2_board[i][j] = L_empty;
        }
    }
    current_dir = horz;
    current_size = 3;
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
        if(can_place_ship(x, y, current_size, current_dir)) {
        for (int i = 0; i < current_size; ++i) {
            if (current_dir == horz) {
                p1_board[x+i][y] = L_ship;
            }
            else {
                p1_board[x][y+i] = L_ship;
            }
        }
        }
       /* if(p1_board[x][y] == L_empty) {
            p1_board[x][y] = L_ship;
        }else if(p1_board[x][y] == L_ship) {
            p1_board[x][y] = L_empty;
        }*/
    }
}

void gamelogic::start_shooting_phase() {
    phase = shooting;
    p2_board[5][5] = L_ship;
}

void gamelogic::handel_click_p2(int x, int y) {
   if (phase == shooting) {
       if (p2_board[x][y] == L_empty || p2_board[x][y] == L_ship) {
           if(p2_board[x][y] == L_ship) {
               p2_board[x][y] = L_hit;
           }
           else if (p2_board[x][y] == L_empty) {
            p2_board[x][y] = L_miss;
           }
            machine_shoot();
       }
   }
}

void gamelogic::machine_shoot() {
    bool valid_shot = false;
    while (!valid_shot) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (p1_board[x][y] != L_empty) {
            p1_board[x][y] = L_miss;
            valid_shot = true;
        }
        else if (p1_board[x][y] == L_ship) {
            p1_board[x][y] = L_hit;
            valid_shot = true;
        }
    }
}

void gamelogic::toggle_direction() {
    if (current_dir == horz) {
        current_dir = vert;
    }
    else {
        current_dir = horz;
    }
}

void gamelogic::set_ship_size(int size) {
    current_size = size;
}
bool gamelogic::can_place_ship(int x, int y,int size,ship_dir dir) {
    for (int i = 0; i < size; ++i) {
        int x_check = x;
        int y_check = y;
        if (dir == horz) {
            x_check += i;
        }
        else {
            y_check += i;
        }
        if (x_check >= 10 || y_check >= 10) {
            return false;
        }
        if (p1_board[x_check][y_check] != L_empty) {
            return false;
        }
        return true;
    }
}