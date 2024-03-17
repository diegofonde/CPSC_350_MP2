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
}

Mario::~Mario(){
    //no pointers to delete
}

void Mario::placeMario(int N){
    int index = N - 1; 
    locationX = rand() % (index);
    locationY = rand() % (index);
}

void Mario::move(int N, std::string &outputString){
    int moveDirection = rand() % 4;
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
    switch (gameObject->getDisplayCharacter()){ //tests type of object based on display character
        case 'm':
            return interactWithMushroom(*gameObject, outputString);
        case 'c':
            return interactWithCoin(*gameObject, outputString);
        case 'w':
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
    int successChance = rand() % 100; 
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