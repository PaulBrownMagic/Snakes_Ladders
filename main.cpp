#include <iostream>
#include "Dice.h"
#include "Player.h"
#include "Board.h"
#include "Messages.h"

using namespace std;

int main() {
    bool is_game_over = false;
    int turn = 0;
    Messages messages;
    messages.print_welcome();
    Dice dice;
    Player player1;
    Player player2;
    Board board;
    board.print(player1.get_position(), player2.get_position());

    while(not is_game_over){
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
           // Check for obstacles
        player1.move(board.obstacle_act(player1.get_position()), board.get_length());
        player2.move(board.obstacle_act(player2.get_position()), board.get_length());
          // Check for game over
        if(player1.get_position() == board.get_length() || player2.get_position() == board.get_length()) {
            is_game_over = true;
        }
        else {
            turn = 1 - turn;
        }

        // Display update
        board.print(player1.get_position(), player2.get_position());
    }
// Game Over
    if(player1.get_position() == board.get_length()) {
        messages.print_winner(turn, player1.get_name());
    }
    else {
        messages.print_winner(turn, player2.get_name());
    }
    return 0;
}