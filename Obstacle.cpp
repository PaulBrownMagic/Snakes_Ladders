//
// Created by brown on 12/06/16.
//

#include "Obstacle.h"
#include <sstream>

Obstacle::Obstacle(string loc, char dir, string dis) {
    stringstream stream;
    stream << loc;
    stream >> location;
    stream.str("");
    stream.clear();
    direction = dir;
    stream << dis;
    stream >> distance;
}

char Obstacle::get_direction() {
    return direction;
}

int Obstacle::get_distance() {
    return distance;
}

int Obstacle::get_location() {
    return location;
}

string Obstacle::get_str_distance() {
    string dis;
    stringstream stream;
    stream << get_distance();
    stream >> dis;
    return dis;
}