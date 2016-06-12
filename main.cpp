#include <iostream>
#include "Dice.h"
#include "Player.h"
#include "Board.h"

using namespace std;

int main() {
    bool is_gameover = false;
    int turn = 0;
    Dice dice;
    Player player1;
    Player player2;
    Board board;
    board.print(player1.get_position(), player2.get_position());

    while(not is_gameover){
        // Event Handling
        if(turn == 0){
            cout << player1.get_name() << ": ";
            player1.move(dice.roll(), board.get_length());
        }
        else {
            cout << player2.get_name() << ": ";
            player2.move(dice.roll(), board.get_length());
        }
        // Run Logic
        if(player1.get_position() == board.get_length() || player2.get_position() == board.get_length()) {
            is_gameover = true;
        }
        turn = 1 - turn;

        // Display update
        board.print(player1.get_position(), player2.get_position());
    }
// Game Over
    if(player1.get_position() == board.get_length()) {
        cout << "Congratulations!" << endl << player1.get_name() <<" WINS!" << endl;
    }
    else {
        cout << "Congratulations!" << endl << player2.get_name() <<" WINS!" << endl;
    }
    return 0;
}