#ifndef GOOMBA_H
#define GOOMBA_H

#include "GameEnemy.h"

class Goomba: GameEnemy{

public: 
    Goomba(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter
    int getwinPercent(); //returns the win percent of the enemy
};

#endif