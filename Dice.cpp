//
// Created by brown on 12/06/16.
//

#include "Dice.h"
#include <iostream>
using namespace std;

Dice::Dice() {
    srand(time(NULL));
}

int Dice::roll() {
    cout << "Press return to roll the dice";
    getline(cin, user_input);
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    if(die1 == die2){
        cout << "You rolled double " << die1 << endl;
        cout << "Move back " << die1 << " spaces" << endl;
        return -die1;
    }
    else{
        cout << "You rolled a " << die1 << " and a " << die2 << endl;
        cout << "Move forward " << die1 + die2 << " spaces." << endl;
        return die1 + die2;
    }
}