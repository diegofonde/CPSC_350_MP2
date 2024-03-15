#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Level.h"
#include "Mario.h"
using namespace std;

class World {
    private:
        int total_levels;
        Level **levels;
        void initializeWorld();
        int dimension;
        int coin_percentage;
        int nothing_percentage;
        int goomba_percentage;
        int koopa_percentage;
        int mushroom_percentage;
        Mario *mario;
    public: 
        World();
        World(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp);

        void addMario(Mario* mario); //passing in Mario to the World
        // ~World();
        void printWorld();

};

#endif