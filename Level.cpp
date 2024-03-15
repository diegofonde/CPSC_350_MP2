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
    grid = new GameObject**[dimension];
    coin_percentage = cp;
    nothing_percentage = np;
    goomba_percentage = gp;
    koopa_percentage = kp;
    mushroom_percentage = mp;

    int_random();


    for (int i = 0; i < dimension; ++i) {
        grid[i] = new GameObject*[dimension];
    }

    //fills the grid with game objects
    for (int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            grid[i][j] = new GameObject();
        }
    }

    initializeGrid();
}

Level :: ~Level() {
    for (int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            delete grid[i][j];
        }
    }

    for (int i = 0; i < dimension; ++i) {
        delete grid[i];
    }

    delete grid;

    delete mario;
}

int Level :: level_num = 0;

void Level :: initializeGrid() {
    if (coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage + mushroom_percentage != 100
    || coin_percentage < 0 || nothing_percentage < 0 || goomba_percentage < 0 || koopa_percentage < 0 || mushroom_percentage < 0) {
        cout << "Invalid input" << endl; //checks if all the percentages added together is 100
    }
    else {

        int remaining_slots = grid_size;

        // for spawning boss
        for(int i = 0; i < 1; ++i) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new LevelBoss(level_num, i_random, j_random);
            }
            else {
                int_random();
            }
        }
        remaining_slots--;

        // for spawning warp pipe
        // makes sure that every level except for the last level has a warp pipe
        if (level_num < total_levels) {
            int total_characters = 0;
            while (total_characters < 1) {
                if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                    grid[i_random][j_random] = new WarpPipe(level_num, i_random, j_random);                    
                    total_characters++;
                    remaining_slots--;
                }
                else {
                    int_random();
                }
            }
        }

        //calculates the spawn rate for coins, nothing, goomba, koopa and mushroom
        int total_coin = remaining_slots * coin_percentage/100;
        int total_nothing = remaining_slots * nothing_percentage/100;
        int total_goomba = remaining_slots * goomba_percentage/100;
        int total_koopa = remaining_slots * koopa_percentage/100;
        int total_mushroom = remaining_slots * mushroom_percentage/100;


        // for spawning coins
        int total_characters = 0;
        while (total_characters < total_coin) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new Coin(level_num, i_random, j_random);                    
                total_characters++;
                remaining_slots--;
            }
            else {
                int_random();
            }
        }

    
        //for spawning nothing
        total_characters = 0;
        while (total_characters < total_nothing) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new Nothing(level_num, i_random, j_random);                    
                total_characters++;
                remaining_slots--;
            }
            else {
                int_random();
            }
        }


        //for spawning goomba       
        total_characters = 0;
        while (total_characters < total_goomba) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new Goomba(level_num, i_random, j_random);                    
                total_characters++;
                remaining_slots--;
            }
            else {
                int_random();
            }
        }

        //for spawning koopa
        total_characters = 0;
        while (total_characters < total_koopa) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new Koopa(level_num, i_random, j_random);                    
                total_characters++;
                remaining_slots--;
            }
            else {
                int_random();
            }
        }


        //for spawning mushroom
        total_characters = 0;
        while (total_characters < remaining_slots) {
            if (grid[i_random][j_random]->getDisplayCharacter() == '\0') {
                grid[i_random][j_random] = new Mushroom(level_num, i_random, j_random);                    
                total_characters++;
            }
            else {
                int_random();
            }
        }



    }


}

//randomizer that is used to spawn the objects in a random part of the grid
void Level :: int_random() {
    int index = dimension - 1;
    i_random = rand() % index;
    j_random = rand() % index;
}


//used to print the level
void Level :: printLevel() {
    for (int i = 0; i < dimension; ++i) {
        if(i != 0) {
           cout << endl; 
        }
        for(int j = 0; j < dimension; ++j) {
            cout << grid[i][j]->getDisplayCharacter();
        }
    }
    
}

void Level::addMario(Mario* mario){
    mario = mario;
    std::cout << mario->getLocationX() << std::endl;
    cout << mario->getLocationY() << endl;
    grid[mario->getLocationX()][mario->getLocationY()] = mario;
    //make mario interact with object 
}