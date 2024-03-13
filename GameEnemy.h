#ifndef GAMEENEMY_H
#define GAMEENEMY_H

#include "GameObject.h"

class GameEnemy: public GameObject{

public: 
    GameEnemy(int level, int locationX, int locationY); //overloaded constructor
    int getwinPercent(); //returns the win percent of the enemy

protected:
    int winPercent;
};

#endif