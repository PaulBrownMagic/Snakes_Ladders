//
// Created by brown on 12/06/16.
//

#ifndef SNAKES_LADDERS_DICE_H
#define SNAKES_LADDERS_DICE_H

#include <string>
using namespace std;


class Dice {
private:
    string user_input;
    int die1;
    int die2;
public:
    Dice();
    int roll();
};


#endif //SNAKES_LADDERS_DICE_H
