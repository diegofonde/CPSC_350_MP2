#include "Level.h"
#include <cstdlib>

// Level::Level() {
//     size = 3;
//     grid = new char*[size];
    
//     for (int i = 0; i < size; ++i) {
//         grid[i] = new char[size];
//     }
// }

Level :: Level(int level_size, int cp, int np, int gp, int kp, int mp) {
    srand((unsigned) time(NULL));
    dimension = level_size;
    grid_size = dimension*dimension;
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

    initializeGrid();
}

void Level :: initializeGrid() {
    if (coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage + mushroom_percentage != 100
    || coin_percentage < 0 || nothing_percentage < 0 || goomba_percentage < 0 || koopa_percentage < 0 || mushroom_percentage < 0) {
        cout << "Invalid input" << endl;
    }
    else {

        for (int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            grid[i][j] = ' ';
        }
    }


        // int empty_space = grid_size;

        grid[i_random][j_random] = 'H';
        // grid_size--;

        // grid[i_random][j_random] = 'b';
        // grid_size--;

        int_random();
        while(grid[i_random][j_random] == ' ') {
            int_random();
            grid[i_random][j_random] = 'b';
            // grid_size--;
        }

        
        // int_random();
        // while(grid[i_random][j_random] == ' ') {
        //     int_random();
        //     grid[i_random][j_random] = 'w';
        //     // grid_size--;
        // }

        int total_coin = grid_size * coin_percentage/100;
        int total_nothing = grid_size * nothing_percentage/100;
        int total_goomba = grid_size * goomba_percentage/100;
        int total_koopa = grid_size * koopa_percentage/100;
        int total_mushroom = grid_size * mushroom_percentage/100;

        // for (int i = 0; i < dimension; ++i) {
        //     for(int j = 0; j < dimension; ++j) {
        //         if (grid[i][j] == NULL){
        //             ;
        //         } 
        //         else {
        //             grid[i][j] = 
        //         }
        
        //     }
        // }

    }


}

void Level :: int_random() {
    i_random = rand() % dimension - 1;
    j_random = rand() % dimension - 1;
}

void Level :: printLevel() {
    for (int i = 0; i < dimension; ++i) {
        cout << endl;
        for(int j = 0; j < dimension; ++j) {
            cout << grid[i][j];
        }
    }
    
}