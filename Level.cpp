#include "Level.h"
#include <cstdlib>
#include <typeinfo>

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
                grid[i_random][j_random] = new GameObject(level_num, i_random, j_random); 
                grid[i_random][j_random]->setDisplayCharacter('x');
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
    cout << "==========" << endl;
    
}

void Level :: outputLevel(ofstream& output) {
    for (int i = 0; i < dimension; ++i) {
        if(i != 0) {
           output << "" << endl; 
        }
        for(int j = 0; j < dimension; ++j) {
            output << grid[i][j]->getDisplayCharacter();
        }
    }
    output << "==========" << endl;
}

void Level::addMario(Mario* mario){
    mario = mario;
    std::cout << mario->getLocationX() << std::endl;
    std::cout << mario->getLocationY() << std::endl;
    //grid[mario->getLocationX()][mario->getLocationY()] = mario;
    //make mario interact with object 
}

bool Level::updateMarioInLevel(Mario* mario, std::ofstream& output, std::string &outputString){
    GameObject *temp = grid[mario->getLocationY()][mario->getLocationX()];
    grid[mario->getLocationY()][mario->getLocationX()] = mario;
    outputLevel(output);
    printLevel();

    bool marioMoves = marioInteractsInLevel(mario, temp, output, outputString);
    delete temp;
    return marioMoves;
}

    bool Level::marioInteractsInLevel(Mario *mario, GameObject *temp, std::ofstream& output, std::string &outputString){

        bool marioClearedSpace = false;

    while (!marioClearedSpace) {
        if (temp->getDisplayCharacter() == 'g' || temp->getDisplayCharacter() == 'k' || temp->getDisplayCharacter() == 'b') {
            GameEnemy* gameEnemy = static_cast<GameEnemy*>(temp);
            std::cout << "mario interacts with enemy" << std::endl;
            marioClearedSpace = mario->interactWithEnemy(*gameEnemy, dimension, outputString);
        }
        else if (temp->getDisplayCharacter() != 'x') {
            std::cout << "mario interacts with object" << std::endl;  
            marioClearedSpace = mario->interactWithObject(temp, dimension, outputString);
        }
        else {
            std::cout << "mario is on a blank space" << std::endl;
            marioClearedSpace = true;
        }

        outputString += " Mario has " + std::to_string(mario->getLives()) + " lives left.";
        outputString += " Mario has " + std::to_string(mario->getCoins()) + " coins.";

        if (temp->getDisplayCharacter() == 'w') {
            outputString += " Mario will WARP.";
            return false;
        }
        else if (marioClearedSpace && temp->getDisplayCharacter() == 'b') {
            return false;
        }
        else if (!marioClearedSpace) {
            outputString += " Mario will stay put.";

            output << outputString << std::endl;
            outputLevel(output);
            outputString = "";
            outputString += "Level: " + std::to_string(mario->getLevel()) + ".";
            outputString += " Mario is at position (" + std::to_string(mario->getLocationX()) + ", " + std::to_string(mario->getLocationY()) + ").";
            outputString += " Mario is at power level " + std::to_string(mario->getPowerLevel()) + ".";
        }
    }

    return marioClearedSpace;
        /*bool marioClearedSpace = false; //tracks if mario has completed the interaction or needs to try again e.g: defeating an enemy
        //outputString += "updating mario interacting in level";
            if (temp->getDisplayCharacter() == 'g' || temp->getDisplayCharacter() == 'k' || temp->getDisplayCharacter() == 'b'){
                GameEnemy* gameEnemy = static_cast<GameEnemy*>(temp); //converting temp to gameEnemy type for the interact method
                //outputString += "mario interacting with enemy";
                std::cout << "mario interacts with enemy" << std::endl;
                marioClearedSpace = mario->interactWithEnemy(*gameEnemy, dimension, outputString);
            }
            else if (temp->getDisplayCharacter() != 'x'){ //mario interacts with object
                //outputString += "mario interacting with object";
                std::cout << "mario interacts with object" << std::endl;  
                marioClearedSpace = mario->interactWithObject(temp, dimension, outputString);
            }
            else{ //mario is on a blank space, nothing happens
                //outputString += "mario lands on a blank space";
                std::cout << "mario is on a blank space" << std::endl;
                marioClearedSpace = true;
            }
            outputString += " Mario has " + std::to_string(mario->getLives()) + " lives left.";
            outputString += " Mario has " + std::to_string(mario->getCoins()) + " coins.";

            if (temp->getDisplayCharacter() == 'w'){
                outputString += " Mario will WARP.";
                return false;
            }
            else if (marioClearedSpace && temp->getDisplayCharacter() == 'b'){ //mario has defeated a boss and does not move normalls
                return false;
            }
            else if (!marioClearedSpace){ //mario has not cleared the space and must try again
                outputString += " Mario will stay put.";

                //outputting, then has mario try again against the same object
                output << outputString << endl;
                outputLevel(output);

                bool spaceCleared = false;
                //while (!spaceCleared){
                    //spaceCleared = marioInteractsInLevel(mario, temp, output, outputString);
                //}
            }
            //TODO: mario defeats boss
            return marioClearedSpace;*/
    }

    void Level::clearMarioFromLevel(Mario* mario){
        if (mario->getLevel() < level_num){
            if (grid[mario->getLocationY()][mario->getLocationX()]->getDisplayCharacter() == 'H'){ //prevents clearing a spot if mario has changed levels
                grid[mario->getLocationY()][mario->getLocationX()] = new GameObject(mario->getLevel(), mario->getLocationY(), mario->getLocationX());
                grid[mario->getLocationY()][mario->getLocationX()]->setDisplayCharacter('x');
            }
        }
    }