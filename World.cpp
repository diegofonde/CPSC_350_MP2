#include "World.h"

// World :: World() {

// }

World :: World(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp) {
    total_levels = num_levels;
    levels = new Level*[num_levels];
    dimension = level_size;
    coin_percentage = cp;
    nothing_percentage = np;
    goomba_percentage = gp;
    koopa_percentage = kp;
    mushroom_percentage = mp;

    initializeWorld();
}

void World :: initializeWorld() {
    for (int i = 0; i < total_levels; ++i) {
        levels[i] = new Level(dimension, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage);
    }
}

void World :: printWorld() {
    for (int i = 0; i < total_levels; ++i) {
        levels[i]->printLevel();
        cout << endl;
    }
    
}