//
// Created by brown on 12/06/16.
//

#ifndef SNAKES_LADDERS_PLAYER_H
#define SNAKES_LADDERS_PLAYER_H
#include <string>
using namespace std;


class Player {
private:
    int position;
    string name;

public:
    Player();
    int move(int spaces, int board_length);
    int get_position();
    string get_name();

};


#endif //SNAKES_LADDERS_PLAYER_H
