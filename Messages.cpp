//
// Created by brown on 12/06/16.
//

#include "Messages.h"
#include <iostream>
#include <fstream>
using namespace std;

void Messages::print_welcome() {
    string line;
    ifstream reader("/home/brown/ClionProjects/Snakes&Ladders/welcome.txt");
    if(!reader){
        cout << "Error opening welcome input file" << endl;
    }
    else {
        while(!reader.eof()) {
            getline(reader, line);
            cout << "\033[31m" << line << "\033[39m" << endl;
        }
    }
    reader.close();
}

void Messages::print_winner(int winner, string name) {
    // int winner is the turn number, the text file must be written so
    // that the first line is for player 1 and the second for player 2
    string lines[4];
    ifstream reader("/home/brown/ClionProjects/Snakes&Ladders/winning.txt");
    if(!reader){
        cout << "Error opening winning messages input file" << endl;
    }
    else {
        // Store file lines in an array, ready to be manipulated
        for(int line = 0; line < 4; line ++){
            getline(reader, lines[line]);
        }
        // First line of hashes
        if(winner == 0){
            cout << "\033[33m";
        }
        else {
            cout << "\033[31m";
        }
        cout << lines[3] << endl;
        // Second line selected for which player has won
        cout << lines[winner] << endl;
        // Third line is hashes
        cout << lines[3] << endl;
        // Start of fourth line, works out how many hashes to print to center text
        for(int h = 0; h < (lines[3].size() - (name.size() + lines[2].size()))/2 - 1; h++ ){
            cout << "#";
        }
        // Print the text with spaces
        cout << " " << name << lines[2] << " ";
        // An even name gets same number of hashes as at the start of the line
        if(name.size() % 2 == 0) {
            for (int h = 0; h < (lines[3].size() - (name.size() + lines[2].size())) / 2 - 1; h++) {
                cout << "#";
            }
        }
            // An odd number gets one more
        else {
            for (int h = 0; h < (lines[3].size() - (name.size() + lines[2].size())) / 2; h++) {
                cout << "#";
            }
        }
        // Last line is a row of hashes
        cout << endl << lines[3] << "\033[39m" << endl;
    }
}