#include "GameEnemy.h"


GameEnemy::GameEnemy(int level, int locationX, int locationY){
    GameObject(level, locationX, locationY);
}

char GameEnemy::getDisplayCharacter(){
    return displayCharacter;
}

int GameEnemy::getwinPercent(){
    return winPercent;
}