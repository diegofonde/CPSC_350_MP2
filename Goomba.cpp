#include "Goomba.h"

Goomba::Goomba(int level, int locationX, int locationY) : GameEnemy(level, locationX, locationY){
    displayCharacter = 'g';
    winPercent = 20;
}