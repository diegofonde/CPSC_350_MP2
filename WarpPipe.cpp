#include "WarpPipe.h"


WarpPipe::WarpPipe(int level, int locationX, int locationY){
    GameObject(level, locationX, locationY);
    displayCharacter = 'w';
}

char WarpPipe::getDisplayCharacter(){
    return displayCharacter;
}