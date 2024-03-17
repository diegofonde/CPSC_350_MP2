#ifndef MARIO_H
#define MARIO_H

#include "GameObject.h"
#include "GameEnemy.h"
#include <fstream>

class Mario: public GameObject{

public: 
    Mario(int inputV); //overloaded constructor that takes in number of lives
    ~Mario(); //destructor

    //primary methods
    bool interactWithObject(GameObject *gameObject, int N, std::string &outputString); //mario interacting with other objects, returns if that object should be deleted
    bool interactWithEnemy(GameEnemy enemy, int N, std::string &outputString); //TODO: integrate into interactWithObject?
    void move(int N, std::string &outputString); //mario has a 25% chance of moving in any direction
    void placeMario(int N); //places mario randomly in the current level

    //setter methods
    void setTotalLevels(int totalLevels); //sets totalLevels so Mario can know when he's won

    //getter method
    bool getMarioHasWon(); //return if mario has won the game
    int getLives(); //returns how many lives mario has left
    int getPowerLevel(); //returns mario's power level
    int getCoins(); //returns how many coins mario has

private:
    int V; //how many lives Mario has
    int coins; //how many coins mario has
    int powerLevel; //mario's power level: 0, 1, or 2
    int enemiesDefeated; //how many enemies mario has defeated on the current life
    int totalLevels; //used for determining if Mario has won

    //interact methods, returns if the interaction is complete (used to determine if mario should try again)
    bool interactWithMushroom(GameObject mushroom, std::string &outputString); 
    bool interactWithCoin(GameObject coin, std::string &outputString);
    bool interactWithWarpPipe(GameObject warpPipe, int N, std::string &outputString);

    //aux methods
    void adjustForLevelWrapping(int N); //adjusts mario's position to fit within level
    void marioDefeatsEnemy(GameEnemy gameEnemy, int N, std::string &outPutString); //mario defeats a normal enemy
    void marioDefeatsBoss(GameEnemy boss, int N); //method for what happens when mario defeats a boss
    void marioLosesToBoss(); //mario loses to a boss
    void marioLosesToEnemy(); //mario loses to a normal enemy
    void marioLosesALife(); //called when mario loses a life
};

#endif