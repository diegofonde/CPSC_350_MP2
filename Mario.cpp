#include "Mario.h"


Mario::Mario(int level, int locationX, int locationY){
    GameObject(level, locationX, locationY);
    displayCharacter = 'H';
}

char Mario::getDisplayCharacter(){
    return displayCharacter;
}