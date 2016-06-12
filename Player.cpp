//
// Created by brown on 12/06/16.
//

#include "Player.h"
#include <iostream>

Player::Player() {
    position = 1;
    cout << "Enter Player's name: ";
    getline(cin, name);
}

int Player::move(int spaces, int board_length) {
    position += spaces;
    if(position > board_length){
        position = board_length;
    }
    else if (position < 1) {
        position = 1;
    }
    return position;
}

int Player::get_position() {
    return position;
}

string Player::get_name() {
    return name;
}