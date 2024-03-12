#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "GameObject.h"

class Mushroom: GameObject{

public: 
    Mushroom(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter

};

#endif