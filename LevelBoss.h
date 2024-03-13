#ifndef LEVELBOSS_H
#define LEVELBOSS_H

#include "GameEnemy.h"

class LevelBoss: public GameEnemy{

public: 
    LevelBoss(int level, int locationX, int locationY); //overloaded constructor
};

#endif