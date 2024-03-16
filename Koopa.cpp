#include "Koopa.h"

Koopa::Koopa(int level, int locationX, int locationY) : GameEnemy(level, locationX, locationY){
    displayCharacter = 'k';
    objectName = "koopa";
    winPercent = 35;
}