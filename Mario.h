#ifndef MARIO_H
#define MARIO_H

#include "GameObject.h"
#include "GameEnemy.h"

class Mario: public GameObject{

public: 
    Mario(int V); //overloaded constructor that takes in number of lives
    Mario(int level, int locationX, int locationY, int V); //overloaded constructor

    //primary methods
    bool interactWithObject(GameObject gameObject); //mario interacting with other objects, returns if that object should be deleted
    bool interactWithEnemy(GameEnemy enemy); //TODO: integrate into interactWithObject?
    void move(); //mario has a 25% chance of moving in any direction
    void placeMario(); //places mario randomly in the current level

    //setter method
    void setN(int N); //sets N so mario can store the level size
    void setTotalLevels(int totalLevels); //sets totalLevels so Mario can know when he's won

    //getter method
    bool getMarioHasWon(); //return if mario has won the game


private:
    int V; //how many lives Mario has
    int coins; //how many coins mario has
    int powerLevel; //mario's power level: 0, 1, or 2
    int enemiesDefeated; //how many enemies mario has defeated on the current life
    int N; //the size of the level, used for move calculations
    int totalLevels; //used for determining if Mario has won
    bool marioHasWon; //if mario has won the game


    //interact methods, returns if the object should be deleted
    bool interactWithMushroom(GameObject mushroom); //TODO: deleteObject?
    bool interactWithCoin(GameObject coin);
    bool interactWithWarpPipe(GameObject warpPipe); //TODO: implement 

    //aux methods
    void adjustForLevelWrapping(); //adjusts mario's position to fit within level
    void marioDefeatsEnemy(GameEnemy gameEnemy); //mario defeats a normal enemy
    void marioDefeatsBoss(GameEnemy boss); //object needed? //TO BE Implemented
    void marioLosesToBoss(); //mario loses to a boss
    void marioLosesToEnemy(); //mario loses to a normal enemy
    void marioLosesALife(); //called when mario loses a life
};

#endif