#ifndef COIN_H
#define COIN_H

#include "GameObject.h"

class Coin: GameObject{

public: 
    Coin(int level, int locationX, int locationY); //overloaded constructor
    char getDisplayCharacter(); //returns displayCharacter

};

#endif