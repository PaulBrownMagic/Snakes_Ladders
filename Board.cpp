//
// Created by brown on 12/06/16.
//

#include "Board.h"
#include <iostream>
using namespace std;

int Board::get_length() {
    return length;
}

void Board::print(int p1_pos, int p2_pos) {
    cout << endl;
    for(int row = 0; row < 7; row++){
        cout << "\033[34m" << "|";
        for(int elem = 0; elem < 7; elem++){
            int tile = tiles[row][elem];
            if(tile == p1_pos && tile == p2_pos){
                cout << "\033[33m" << "P1" << "\033[31m" << "P2" << "\033[34m|";
            }
            else if(tile == p1_pos){
                cout << "\033[33m" <<"*P1*" << "\033[34m|";
            }
            else if(tile == p2_pos){
                cout << "\033[31m" << "*P2*" << "\033[34m|";
            }
            else if (tile < 10){
                cout << " 0" << tile << " |";
            }
            else {
                cout << " " << tile << " |";
            }
        }
        cout << "\033[39m" << endl;
    }
    cout << endl;
}