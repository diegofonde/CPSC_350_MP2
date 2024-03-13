#ifndef KOOPA_H
#define KOOPA_H

#include "GameEnemy.h"

class Koopa: public GameEnemy{

public: 
    Koopa(int level, int locationX, int locationY); //overloaded constructor
};

#endif