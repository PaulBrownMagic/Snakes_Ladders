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
        cout << "|";
        for(int elem = 0; elem < 7; elem++){
            int tile = tiles[row][elem];
            if(tile == p1_pos && tile == p2_pos){
                cout << "P1P2|";
            }
            else if(tile == p1_pos){
                cout << "*P1*|";
            }
            else if(tile == p2_pos){
                cout << "*P2*|";
            }
            else if (tile < 10){
                cout << " 0" << tile << " |";
            }
            else {
                cout << " " << tile << " |";
            }
        }
        cout << endl;
    }
    cout << endl;
}