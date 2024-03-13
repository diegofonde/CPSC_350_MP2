#ifndef COIN_H
#define COIN_H

#include "GameObject.h"

class Coin: public GameObject{

public: 
    Coin(int level, int locationX, int locationY); //overloaded constructor
};

#endif