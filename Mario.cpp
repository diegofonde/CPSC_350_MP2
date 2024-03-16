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

void Mario::move(int N){
    std::cout << "LocationX: " << locationX << " locationY: " << locationY << std::endl;
    int moveDirection = rand() % 4;
    std::cout << moveDirection << std::endl;
    switch (moveDirection){
        case 0: //up
            locationY++;
            std::cout << "mario moved up" << std::endl;
            break;
        case 1: //down
            locationY--;
            std::cout << "mario moved down" << std::endl;
            break;
        case 2: //left
            locationX--;
            std::cout << "mario moved left" << std::endl;
            break;
        case 3: //right
            locationX++;
            std::cout << "mario moved right" << std::endl;
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

bool Mario::interactWithObject(GameObject *gameObject, int N){
    switch (gameObject->getDisplayCharacter()){ //tests type of object based on display character
        case 'm':
            return interactWithMushroom(*gameObject);
        case 'c':
            return interactWithCoin(*gameObject);
        case 'w':
            return interactWithWarpPipe(*gameObject, N);
        case 'g' || 'k' || 'b': //gameObject is an enemy
            //GameEnemy* gameEnemy = static_cast<GameEnemy*>(gameObject);
            //return interactWithEnemy(*gameEnemy);
        default:
            return false;
            //TODO: throw error
    }
}

bool Mario::interactWithMushroom(GameObject mushroom){
    std::cout << "mario ate a mushroom" << std::endl;
    if (powerLevel != 2){
        powerLevel++;
    }
    return true;
}

bool Mario::interactWithCoin(GameObject coin){
    std::cout << "mario picked up a coin" << std::endl;
    if (++coins == 20){
        coins = 0;
        V++;
    }
    else{
        coins++;
    }
    return true;
}

bool Mario::interactWithWarpPipe(GameObject warpPipe, int N){
    std::cout << "mario traveled through a warp pipe" << std::endl;
    level++;
    placeMario(N);
    return true;
}

bool Mario::interactWithEnemy(GameEnemy enemy, int N){
    int successChance = rand() % 100; //TODO: improve random number?
    std::cout << "enemy" << std::endl;
    if (successChance > enemy.getwinPercent()){ //mario Wins
        marioDefeatsEnemy(enemy, N);
        return true;
    }
    else{ //mario looses
        if (enemy.getDisplayCharacter() == 'b'){
            marioLosesToBoss();
        }
        else{
            marioLosesToEnemy();
        }
        return false;
    }
}

void Mario::marioDefeatsEnemy(GameEnemy enemy, int N){
    if (++enemiesDefeated == 7){ //adds another life if mario has defeated 7 enemies
        V++;
        enemiesDefeated = 0;
        std::cout << "mario has defeated 7 enemies and gained a life" << std::endl;
    }
    if (enemy.getDisplayCharacter() == 'b'){ //mario has defeated a boss
        marioDefeatsBoss(enemy, N);
    }
    std::cout << "mario defeats enemy" << std::endl;
}

void Mario::marioDefeatsBoss(GameEnemy boss, int N){
        level++;
        placeMario(N);
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