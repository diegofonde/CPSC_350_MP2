#include "Level.h"

// Level::Level() {
//     size = 3;
//     grid = new char*[size];
    
//     for (int i = 0; i < size; ++i) {
//         grid[i] = new char[size];
//     }
// }

Level :: Level(int level_size, int cp, int np, int gp, int kp, int mp) {
    size = level_size;
    grid = new char*[size];
    coin_percentage = cp;
    nothing_percentage = np;
    goomba_percentage = gp;
    koopa_percentage = kp;
    mushroom_percentage = mp;

    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
    }

    // for (int i = 0; i < size; ++i) {
    //     for(int j = 0; j < size; ++j) {
    //         grid[i][j] = 'a';
    //     }
    // }
}

void Level :: initializeGrid() {
    if (coin_percentage + nothing_percentage + goomba_percentage + koopa_percentage + mushroom_percentage != 100
    || coin_percentage < 0 || nothing_percentage < 0 || goomba_percentage < 0; koopa_percentage < 0 || mushroom_percentage < 0) {
        cout << "Invalid input" << endl;
    }
    else {
        
    }


}

void Level :: printLevel() {
    for (int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            cout << grid[i][j] << endl;
        }
    }
    
}