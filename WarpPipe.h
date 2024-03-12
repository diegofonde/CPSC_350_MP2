#ifndef WARPPIPE_H
#define WARPPIPE_H

#include "GameObject.h"

class WarpPipe: GameObject{

public: 
    WarpPipe(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter
};

#endif