#include <iostream>

#include "Game.h"
#include "mushroom.h"
#include "coin.h"
#include "WarpPipe.h"
#include "Goomba.h"
#include "Mario.h"
#include "GameEnemy.h"
#include "Koopa.h"
#include "LevelBoss.h"

int main(){
    /*Game *testGame = new Game("input-spec.txt", "log.txt");
    testGame->runGame();
    delete testGame;*/

    LevelBoss *testGoomba = new LevelBoss(0,0,0);   
    std::cout << testGoomba->getDisplayCharacter() << std::endl;
    std::cout << testGoomba->getwinPercent() << std::endl;
    delete testGoomba;
}
