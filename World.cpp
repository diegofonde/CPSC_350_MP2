#include "World.h"

World :: World() {
    total_levels = 0;
    levels = 0;
    dimension = 0;
    coin_percentage = 0;
    nothing_percentage = 0;
    goomba_percentage = 0;
    koopa_percentage = 0;
    mushroom_percentage = 0;

}

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
        levels[i] = new Level(total_levels, dimension, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage);
    }
}

void World :: printWorld() {
    for (int i = total_levels - 1; i >= 0; --i) {
        levels[i]->printLevel();
        cout << "==========" << endl;
    }
    
}