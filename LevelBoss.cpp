#include "LevelBoss.h"

LevelBoss::LevelBoss(int level, int locationX, int locationY) : GameEnemy(level, locationX, locationY){
    displayCharacter = 'b';
    winPercent = 50;
}