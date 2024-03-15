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

World :: ~World() {
    for (int i = 0; i < total_levels; ++i) {
        delete levels[i];
    }

    delete levels;

    delete mario;
}

void World::addMario(Mario* mario){
    mario = mario;
    // mario->setN(dimension); setter doesn't work
    // cout << mario->getN() << endl;
    levels[0]->addMario(mario);
}

//Keeps making level objects based on the value of total_levels
void World :: initializeWorld() {
    for (int i = 0; i < total_levels; ++i) {
        levels[i] = new Level(total_levels, dimension, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage);
    }
}

//prints out all the levels in world
void World :: printWorld() {
    for (int i = 0; i < total_levels; ++i) {
        levels[i]->printLevel();
        cout << "==========" << endl;
    }
    
}