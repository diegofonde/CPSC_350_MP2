#include "LevelBoss.h"

LevelBoss::LevelBoss(int level, int locationX, int locationY) : GameEnemy(level, locationX, locationY){
    displayCharacter = 'b';
    objectName = "boss";
    winPercent = 50;
}