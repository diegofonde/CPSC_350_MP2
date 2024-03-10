#include "Level.h"
#include <cstdlib>

Level::Level() {
    srand((unsigned) time(NULL));
    total_levels = 0;
    dimension = 0;
    grid_size = 0;
    level_num++;
    grid = 0;
    coin_percentage = 0;
    nothing_percentage = 0;
    goomba_percentage = 0;
    koopa_percentage = 0;
    mushroom_percentage = 0;
}

Level :: Level(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp) {
    srand((unsigned) time(NULL));
    total_levels = num_levels;
    dimension = level_size + 1;
    grid_size = level_size * level_size;
    level_num++;
    grid = new char*[dimension];
    coin_percentage = cp;
    nothing_percentage = np;
    goomba_percentage = gp;
    koopa_percentage = kp;
    mushroom_percentage = mp;

    int_random();

    for (int i = 0; i < dimension; ++i) {
        grid[i] = new char[dimension];
    }

    for (int i = 0; i < dimension; ++i) {
            for(int j = 0; j < dimension; ++j) {
                grid[i][j] = ' ';
            }
        }

    initializeGrid();
}

int Level :: level_num = 0;

void Level :: initializeGrid() {
    if (coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage + mushroom_percentage != 100
    || coin_percentage < 0 || nothing_percentage < 0 || goomba_percentage < 0 || koopa_percentage < 0 || mushroom_percentage < 0) {
        cout << "Invalid input" << endl;
    }
    else {

        int remaining_slots = grid_size;

        // for spawning Mario
        if (level_num == 1) {
            char Mario = 'H';
            spawn_object(1, Mario);
            remaining_slots -= 1;
        }

        // for spawning Boss
        char Boss = 'b';
        spawn_object(1, Boss);
        remaining_slots -= 1;

        // for spawning world pipe
        if (level_num != total_levels) {
            char World_pipe = 'w';
            spawn_object(1, World_pipe);
            remaining_slots -= 1;   
        }

        char World_pipe = 'w';
        spawn_object(1, World_pipe);
        remaining_slots -= 1;

        int total_coin = remaining_slots * coin_percentage/100;
        int total_nothing = remaining_slots * nothing_percentage/100;
        int total_goomba = remaining_slots * goomba_percentage/100;
        int total_koopa = remaining_slots * koopa_percentage/100;
        int total_mushroom = remaining_slots * mushroom_percentage/100;

        //spawns coins
        char coin = 'c';
        spawn_object(total_coin, coin);
        remaining_slots -= total_coin;

        //spawns nothing
        char nothing = 'x';
        spawn_object(total_nothing, nothing);
        remaining_slots -= total_nothing;

        //spawns goomba
        char goomba = 'g';
        spawn_object(total_goomba, goomba);
        remaining_slots -= total_goomba;

        //spawns koopa
        char koopa = 'k';
        spawn_object(total_koopa, koopa);
        remaining_slots -= total_koopa;

        //spawns mushroom
        char mushroom = 'm';
        spawn_object(remaining_slots, mushroom);


    }


}

void Level :: int_random() {
    int index = dimension - 1;
    i_random = rand() % index;
    j_random = rand() % index;
}

void Level :: spawn_object(int num, char c) {
    int total_characters = 0;
    while (total_characters < num) {
        if (grid[i_random][j_random] == ' ') {
            grid[i_random][j_random] = c;
            total_characters++;
        }
        else {
            int_random();
        }
        
    }
}


void Level :: printLevel() {
    for (int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}