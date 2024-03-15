#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "GameObject.h"
#include "GameEnemy.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "LevelBoss.h"
#include "Coin.h"
#include "WarpPipe.h"
#include "Nothing.h"
#include "Mushroom.h"
using namespace std;

class Level {
    private: 
        int total_levels;
        int dimension;
        int grid_size;
        static int level_num;
        GameObject ***grid;
        int coin_percentage;
        int nothing_percentage;
        int goomba_percentage;
        int koopa_percentage;
        int mushroom_percentage;
        void initializeGrid();
        unsigned int i_random;
        unsigned int j_random;
        void int_random();
        Mario *mario;
        // void spawn_object(int num, char c);
    public: 
        Level();
        Level(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp);
        // ~Level();
        void printLevel();
        //void spawnMario();
        void addMario(Mario* mario); //adds mario to the level
};

#endif