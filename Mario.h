#ifndef MARIO_H
#define MARIO_H

#include "GameObject.h"

class Mario: GameObject{

public: 
    Mario(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter

};

#endif