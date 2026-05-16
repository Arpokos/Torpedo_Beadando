
#ifndef CLIONGRAPHICSKIT_GAMELOGIC_HPP
#define CLIONGRAPHICSKIT_GAMELOGIC_HPP

enum logicstate{L_empty,L_ship,L_hit,L_miss};
enum gamephase{prep,shooting,gameover};
enum ship_dir{horz,vert};
class gamelogic {
    protected:
    logicstate p1_board[10][10];
    logicstate p2_board[10][10];
    int current_player;
    gamephase phase;
    ship_dir current_dir;
    int current_size;
    public:
    gamelogic();
    logicstate get_p1_cell(int x, int y) const;
    logicstate get_p2_cell(int x, int y) const;
    gamephase get_phase() const;
    void handel_click_p1(int x, int y);
    void handel_click_p2(int x, int y);
    void start_shooting_phase();
    void toggle_direction();
    void set_ship_size(int size);
    bool can_place_ship(int x, int y,int size,ship_dir dir);
    void machine_shoot();
};


#endif //CLIONGRAPHICSKIT_GAMELOGIC_HPP