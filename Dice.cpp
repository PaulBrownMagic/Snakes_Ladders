//
// Created by brown on 12/06/16.
//

#include "Dice.h"
#include <iostream>
using namespace std;

Dice::Dice() {
    srand(static_cast<unsigned int>(time(NULL)));
}

int Dice::roll() {
    cout << "Press return to roll the dice";
    getline(cin, user_input);
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    if(die1 == die2){
        cout << "\033[35m" << "You rolled\033[36m double " << die1 << "\033[35m" << endl;
        cout << "Move back " << "\033[36m" << die1 + die2 << "\033[35m" << " spaces" << endl << "\033[39m";
        return -(die1 + die2);
    }
    else{
        cout << "\033[36m" <<  "You rolled a " << die1 << " and a " << die2 << endl;
        cout << "Move forward " << "\033[35m" << die1 + die2 << "\033[36m"<< " spaces." << endl << "\033[39m";
        return die1 + die2;
    }
}