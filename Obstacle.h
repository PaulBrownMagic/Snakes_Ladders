//
// Created by brown on 12/06/16.
//

#ifndef SNAKES_LADDERS_OBSTACLE_H
#define SNAKES_LADDERS_OBSTACLE_H

#include <string>
using namespace std;

class Obstacle {
private:
    int location;
    char direction;
    int distance;
public:
    void set_obstacle(string loc, char dir, string dis);
    int get_location();
    char get_direction();
    int get_distance();
    string get_str_distance();
};


#endif //SNAKES_LADDERS_OBSTACLE_H
