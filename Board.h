//
// Created by brown on 12/06/16.
//

#ifndef SNAKES_LADDERS_BOARD_H
#define SNAKES_LADDERS_BOARD_H

#include "Obstacle.h"
#include <vector>


class Board {
private:
    int tiles[7][7] = {
            {43, 44, 45, 46, 47, 48, 49},
            {42, 41, 40, 39, 38, 37, 36},
            {29, 30, 31, 32, 33, 34, 35},
            {28, 27, 26, 25, 24, 23, 22},
            {15, 16, 17, 18, 19, 20, 21},
            {14 ,13, 12, 11, 10, 9, 8},
            {1, 2, 3, 4, 5, 6, 7}
    };
    int length = tiles[0][6];
    vector <Obstacle> obstacles;
    vector <int> obstacle_locations;
    string get_obstacle_tile(int loc);
    int number_of_obstacles;
    bool tile_is_obstacle(int tile);
public:
    Board();
    int get_length();
    void print(int p1_pos, int p2_pos);
    int obstacle_act(int pos);
};


#endif //SNAKES_LADDERS_BOARD_H
