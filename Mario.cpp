#include <cstdlib> 
#include <ctime>

#include "Mario.h"
#include "GameEnemy.h"
#include <iostream>

Mario::Mario(int inputV) : GameObject(){
    srand((unsigned) time(NULL));
    displayCharacter = 'H';
    V = inputV;
    coins = 0;
    powerLevel = 0;
    enemiesDefeated = 7;
    marioHasWon = false;
    //std::cout << V << std::endl;
}

//Needed??
Mario::Mario(int level, int locationX, int locationY, int V) : GameObject(level, locationX, locationY){
    srand((unsigned) time(NULL));
    displayCharacter = 'H';
    V = V;
    coins = 0;
    powerLevel = 0;
    enemiesDefeated = 0;
    locationX = 5;
}

void Mario::placeMario(int N){
    int index = N - 1; //if you want to double check if the randomizer works just replace N with the dimensions of level
    //std::cout << N << std::endl;
    locationX = rand() % (index);
    locationY = rand() % (index);
}

void Mario::move(int N, std::string &outputString){
    std::cout << "LocationX: " << locationX << " locationY: " << locationY << std::endl;
    int moveDirection = rand() % 4;
    std::cout << moveDirection << std::endl;
    switch (moveDirection){
        case 0: //down
            locationY++;
            std::cout << "mario moved down" << std::endl;
            outputString += " Mario will move down.";
            break;
        case 1: //up
            locationY--;
            std::cout << "mario moved up" << std::endl;
            outputString += " Mario will move up.";
            break;
        case 2: //left
            locationX--;
            std::cout << "mario moved left" << std::endl;
            outputString += " Mario will move left.";
            break;
        case 3: //right
            locationX++;
            std::cout << "mario moved right" << std::endl;
            outputString += " Mario will move right.";
            break;
    }
    adjustForLevelWrapping(N);
}

void Mario::adjustForLevelWrapping(int N){
    //std::cout << "wrapping called" << std::endl;
    std::cout << "LocationX: " << locationX << " locationY: " << locationY << std::endl;
    if (locationY >= N){ //up
        locationY = 0;
        std::cout << "wrapping up" << std::endl;
    }
    else if (locationY < 0){ //down
        locationY = N-1;
        std::cout << "wrapping down" << std::endl;
    }
    else if (locationX < 0){ //left
        locationX = N-1;
        std::cout << "wrapping left" << std::endl;
    }
    else if (locationX >= N){ //right
        locationX = 0;
        std::cout << "wrapping right" << std::endl;
    }
}

bool Mario::interactWithObject(GameObject *gameObject, int N, std::string &outputString){
    //outputString += "mario interacting with object 2";
    switch (gameObject->getDisplayCharacter()){ //tests type of object based on display character
        case 'm':
            //outputString += "mario interacting with mushroom";
            return interactWithMushroom(*gameObject, outputString);
        case 'c':
        //outputString += "mario interacting with coin";
            return interactWithCoin(*gameObject, outputString);
        case 'w':
        //outputString += "mario interacting with warp pipe";
            return interactWithWarpPipe(*gameObject, N, outputString);
    }
    return false;
}

bool Mario::interactWithMushroom(GameObject mushroom, std::string &outputString){
    outputString += " Mario ate a mushroom.";
    if (powerLevel != 2){
        powerLevel++;
    }
    return true;
}

bool Mario::interactWithCoin(GameObject coin, std::string &outputString){
    outputString += " Mario picked up a coin.";
    if (++coins == 20){
        coins = 0;
        V++;
    }
    return true;
}

bool Mario::interactWithWarpPipe(GameObject warpPipe, int N, std::string &outputString){
    outputString += " Mario found a warp pipe.";
    level++;
    placeMario(N);
    return true;
}

bool Mario::interactWithEnemy(GameEnemy enemy, int N, std::string &outputString){
    int successChance = rand() % 100; //TODO: improve random number?
    std::cout << "enemy" << std::endl;
    outputString += " Mario encountered a " + enemy.getObjectName() + " and ";
    if (successChance > enemy.getwinPercent()){ //mario Wins
        marioDefeatsEnemy(enemy, N, outputString);
        return true;
    }
    else{ //mario looses
        outputString += "lost.";
        if (enemy.getDisplayCharacter() == 'b'){
            marioLosesToBoss();
        }
        else{
            marioLosesToEnemy();
        }
        if (V <= 0){ //mario is dead
                return true;
            }
        return false;
    }
}

void Mario::marioDefeatsEnemy(GameEnemy enemy, int N, std::string &outputString){
    if (++enemiesDefeated == 7){ //adds another life if mario has defeated 7 enemies
        V++;
        enemiesDefeated = 0;
        std::cout << "mario has defeated 7 enemies and gained a life" << std::endl;
    }
    std::cout << "mario defeats enemy" << std::endl;
    if (enemy.getDisplayCharacter() == 'b'){ //mario has defeated a boss
        marioDefeatsBoss(enemy, N);
        if (level < totalLevels){
            outputString += "won, so will advance to the next level.";
        }
        else{
            outputString += "won.";
        }
    }
    else{
        outputString += "won.";
    }
}

void Mario::marioDefeatsBoss(GameEnemy boss, int N){
    //if (level == totalLevels - 1){ //mario has won
        //marioHasWon = true;
        //std::cout << "mario has beat the last level" << std::endl;
    //}
    //else{
        level++;
        placeMario(N);
    //}
    //std::cout << "setting lives to 0 for a test" << std::endl;
    //V = 0;
    std::cout << "mario defeats boss" << std::endl;
}

void Mario::marioLosesToBoss(){
    if (powerLevel == 2){ //reduces powerLevel
        powerLevel = 0;
    }
    else{
        marioLosesALife();
    }
    std::cout << "mario loses to boss" << std::endl;
}

void Mario::marioLosesToEnemy(){
    if (powerLevel > 0){ //reduces powerLevel
        powerLevel--;
    }
    else{
        marioLosesALife();
    }
    std::cout << "mario loses to enemy" << std::endl;
}

void Mario::marioLosesALife(){
    V--;
    powerLevel = 0;
    enemiesDefeated = 0;
}

// int Mario :: getN() {
//     return N;
// }

void Mario::setTotalLevels(int totalLevels){
    totalLevels = totalLevels;
}

int Mario::getLives(){
    return V;
}

int Mario::getPowerLevel(){
    return powerLevel;
}

int Mario::getCoins(){
    return coins;
}