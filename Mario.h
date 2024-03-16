#ifndef MARIO_H
#define MARIO_H

#include "GameObject.h"
#include "GameEnemy.h"

class Mario: public GameObject{

public: 
    Mario(int inputV); //overloaded constructor that takes in number of lives
    Mario(int level, int locationX, int locationY, int V); //overloaded constructor

    //primary methods
    bool interactWithObject(GameObject *gameObject, int N); //mario interacting with other objects, returns if that object should be deleted
    bool interactWithEnemy(GameEnemy enemy, int N); //TODO: integrate into interactWithObject?
    void move(int N); //mario has a 25% chance of moving in any direction
    void placeMario(int N); //places mario randomly in the current level

    //setter methods
    void setTotalLevels(int totalLevels); //sets totalLevels so Mario can know when he's won

    //getter method
    bool getMarioHasWon(); //return if mario has won the game
    int getLives(); //returns how many lives mario has left
    // int getN();

private:
    int V; //how many lives Mario has
    int coins; //how many coins mario has
    int powerLevel; //mario's power level: 0, 1, or 2
    int enemiesDefeated; //how many enemies mario has defeated on the current life
    int *N; //the size of the level, used for move calculations
    int totalLevels; //used for determining if Mario has won
    bool marioHasWon; //if mario has won the game

    //interact methods, returns if the object should be deleted
    bool interactWithMushroom(GameObject mushroom); //TODO: deleteObject?
    bool interactWithCoin(GameObject coin);
    bool interactWithWarpPipe(GameObject warpPipe, int N); //TODO: implement 

    //aux methods
    void adjustForLevelWrapping(int N); //adjusts mario's position to fit within level
    void marioDefeatsEnemy(GameEnemy gameEnemy, int N); //mario defeats a normal enemy
    void marioDefeatsBoss(GameEnemy boss, int N); //object needed? //TO BE Implemented
    void marioLosesToBoss(); //mario loses to a boss
    void marioLosesToEnemy(); //mario loses to a normal enemy
    void marioLosesALife(); //called when mario loses a life
};

#endif