
#ifndef CLIONGRAPHICSKIT_GAMELOGIC_HPP
#define CLIONGRAPHICSKIT_GAMELOGIC_HPP

enum logicstate{L_empty,L_ship,L_hit,L_miss};
enum gamephase{prep,shooting,gameover};
class gamelogic {
    protected:
    logicstate p1_board[10][10];
    logicstate p2_board[10][10];
    int current_player;
    gamephase phase;
    public:
    gamelogic();
    logicstate get_p1_cell(int x, int y) const;
    logicstate get_p2_cell(int x, int y) const;
    gamephase get_phase() const;
    void handel_click_p1(int x, int y);
    void handel_click_p2(int x, int y);
    void start_shooting_phase();
};


#endif //CLIONGRAPHICSKIT_GAMELOGIC_HPP