#ifndef GOOMBA_H
#define GOOMBA_H

#include "GameEnemy.h"

class Goomba: public GameEnemy{

public: 
    Goomba(int level, int locationX, int locationY); //overloaded constructor
};

#endif