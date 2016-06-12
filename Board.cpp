//
// Created by brown on 12/06/16.
//

#include "Board.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board() {
    number_of_obstacles = 0;
    ifstream reader("/home/brown/ClionProjects/Snakes&Ladders/obstacles");
    if(!reader){
        cout << "Error, could not read obstacles input file" << endl;
    }
    else {
        string line;
        while(!reader.eof()){
            getline(reader, line);
            unsigned long f_comma = line.find_first_of(",");
            unsigned long l_comma = line.find_last_of(",");
            Obstacle obs;
            obs.set_obstacle(line.substr(0, f_comma), line.at(f_comma + 1),
                             line.substr(l_comma+1,line.size()-l_comma));
            obstacles.push_back(obs);
            obstacle_locations.push_back(obstacles[number_of_obstacles].get_location());
            number_of_obstacles += 1;
        }
    }
    reader.close();
}

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
            else if(tile_is_obstacle(tile)){
                cout << get_obstacle_tile(tile);
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

string Board::get_obstacle_tile(int loc) {
    for(int t = 0; t < number_of_obstacles; t++){
        if(obstacle_locations[t] == loc){
            string tile;
            char dir = obstacles[t].get_direction();
            if(dir == 'F'){
                tile += "+F";
                tile += obstacles[t].get_str_distance();
                tile += "+|";
                return tile;
            }
            else{
                tile += "-B";
                tile += obstacles[t].get_str_distance();
                if(obstacles[t].get_distance() < 10){
                    tile += "-|";
                }
                else{
                    tile += "|";
                }
                return tile;
            }
        }
    }
    return "ERROR, not an obstacle";
}

int Board::obstacle_act(int pos) {
    for (int t = 0; t < number_of_obstacles; t++) {
        if (obstacle_locations[t] == pos) {
            if(obstacles[t].get_direction() == 'F'){
                cout << "You hit an obstacle! Move forward " << obstacles[t].get_distance() << " spaces" << endl;
                return obstacles[t].get_distance();
            }
            else{
                cout << "You hit an obstacle! Move back " << obstacles[t].get_distance() << " spaces" << endl;
                return -obstacles[t].get_distance();
            }
        }

    }
    return 0;
}

bool Board::tile_is_obstacle(int tile) {
    for(int i = 0; i < obstacle_locations.size(); i++){
        if(obstacle_locations[i] == tile){
            return true;
        }
    }
    return false;
}