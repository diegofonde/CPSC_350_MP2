#include <cstdlib> 
#include <ctime>

#include "Mario.h"

Mario::Mario(int V) : GameObject(){
    displayCharacter = 'H';
    V = V;
    coins = 0;
    powerLevel = 0;
    enemiesDefeated = 7;
    marioHasWon = false;
}

//Needed??
Mario::Mario(int level, int locationX, int locationY, int V) : GameObject(level, locationX, locationY){
    displayCharacter = 'H';
    V = V;
    coins = 0;
    powerLevel = 0;
    enemiesDefeated = 0;
}

void Mario::placeMario(){
    locationX = rand() % (N);
    locationY = rand() % (N);
}

void Mario::move(){
    int moveDirection = rand() % 4;
    switch (moveDirection){
        case 0: //up
            locationY++;
        case 1: //down
            locationY--;
        case 2: //left
            locationX--;
        case 3: 
            locationX++;
    }
    adjustForLevelWrapping();
}

void Mario::adjustForLevelWrapping(){
    if (locationY >= N){ //up
        locationY = 0;
    }
    else if (locationY < 0){ //down
        locationY = N-1;
    }
    else if (locationX < 0){ //left
        locationX = N-1;
    }
    else if (locationX >= N){ //right
        locationX = 0;
    }
}

bool Mario::interactWithObject(GameObject gameObject){
    switch (gameObject.getDisplayCharacter()){ //tests type of object based on display character
        case 'm':
            return interactWithMushroom(gameObject);
        case 'c':
            return interactWithCoin(gameObject);
        case 'w':
            return interactWithWarpPipe(gameObject); //TODO: include interact with gameenemy here?
        default:
            return false;
            //TODO: throw error
    }
}

bool Mario::interactWithMushroom(GameObject mushroom){
    if (powerLevel != 2){
        powerLevel++;
    }
    return true;
}

bool Mario::interactWithCoin(GameObject coin){
    if (++coins == 20){
        coins = 0;
        V++;
    }
    else{
        coins++;
    }
    return true;
}

bool Mario::interactWithWarpPipe(GameObject warpPipe){
    level++;
    placeMario();
    return true;
}

bool Mario::interactWithEnemy(GameEnemy enemy){
    int successChance = rand() % 101; //TODO: improve random number?
    if (successChance > enemy.getwinPercent()){ //mario Wins
        marioDefeatsEnemy(enemy);
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

void Mario::marioDefeatsEnemy(GameEnemy enemy){
    if (++enemiesDefeated == 7){ //adds another life if mario has defeated 7 enemies
        V++;
        enemiesDefeated = 0;
    }
    if (enemy.getDisplayCharacter() == 'b'){ //mario has defeated a boss
        marioDefeatsBoss(enemy);
    }
}

void Mario::marioDefeatsBoss(GameEnemy boss){
    if (totalLevels == level){ //mario has defeated the last boss //Need to to total levels - 1?
        marioHasWon = true;
    }
    else{ //mario moves on to the next level
        level++;
        placeMario();
    }
}

void Mario::marioLosesToBoss(){
    if (powerLevel == 2){ //reduces powerLevel
        powerLevel = 0;
    }
    else{
        marioLosesALife();
    }
}

void Mario::marioLosesToEnemy(){
    if (powerLevel > 0){ //reduces powerLevel
        powerLevel--;
    }
    else{
        marioLosesALife();
    }
}

void Mario::marioLosesALife(){
    V--;
    powerLevel = 0;
    enemiesDefeated = 0;
}

void Mario::setN(int N){
    N = N;
}

void Mario::setTotalLevels(int totalLevels){
    totalLevels = totalLevels;
}