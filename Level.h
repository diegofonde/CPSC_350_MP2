#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <random>
using namespace std;

class Level {
    private: 
        int size;
        char **grid;
        int coin_percentage;
        int nothing_percentage;
        int goomba_percentage;
        int koopa_percentage;
        int mushroom_percentage;
        void initializeGrid();
    public: 
        // Level();
        Level(int level_size, int cp, int np, int gp, int kp, int mp);
        // ~Level();
        void printLevel();
};

#endif