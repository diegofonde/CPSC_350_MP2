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
    //void Move(); TODO

private:
    int V; //how many lives Mario has
    int coins; //how many coins mario has
    int powerLevel; //mario's power level: 0, 1, or 2
    int enemiesDefeated; //how many enemies mario has defeated on the current life

    //interact methods, returns if the object should be deleted
    bool interactWithMushroom(GameObject mushroom); //TODO: deleteObject?
    bool interactWithCoin(GameObject coin);
    bool interactWithWarpPipe(GameObject warpPipe); //TODO: implement 

    //aux methods
    void marioDefeatsEnemy(GameEnemy gameEnemy);
    void marioDefeatsBoss(GameEnemy boss); //object needed? //TO BE Implemented
    void marioLosesToBoss(); //mario loses to a boss
    void marioLosesToEnemy(); //mario loses to a normal enemy
    void marioLosesALife(); //called when mario loses a life
};

#endif