#include "GameEnemy.h"


GameEnemy::GameEnemy(int level, int locationX, int locationY): GameObject(level, locationX, locationY){

}

int GameEnemy::getwinPercent(){
    return winPercent;
}