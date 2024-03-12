#include <iostream>

#include "Game.h"
#include "mushroom.h"
#include "coin.h"
#include "WarpPipe.h"

int main(){
    Game *testGame = new Game("input-spec.txt", "log.txt");
    delete testGame; 

    //WarpPipe *testMushroom = new WarpPipe(0, 0, 0);   
    //std::cout << testMushroom->getDisplayCharacter() << std::endl;
    //delete testMushroom;
}
