#ifndef GAMEENEMY_H
#define GAMEENEMY_H

#include "GameObject.h"

class GameEnemy: GameObject{

public: 
    GameEnemy(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter
    int getwinPercent(); //returns the win percent of the enemy

protected:
    int winPercent;
};

#endif