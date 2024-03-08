#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Level {
    private: 
        int dimension;
        int grid_size;
        char **grid;
        int coin_percentage;
        int nothing_percentage;
        int goomba_percentage;
        int koopa_percentage;
        int mushroom_percentage;
        void initializeGrid();
        unsigned int i_random;
        unsigned int j_random;
        void int_random();
    public: 
        // Level();
        Level(int level_size, int cp, int np, int gp, int kp, int mp);
        // ~Level();
        void printLevel();
};

#endif