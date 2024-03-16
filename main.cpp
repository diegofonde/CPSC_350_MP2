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

int main(int argc, char* argv[]){

    Game *testGame = new Game("input-spec.txt", "log2.txt");
    testGame->runGame();
    delete testGame;

    /*std::string inputFile = (std::string)argv[1];
    std::string outputFile = (std::string)argv[2];
    
    std::cout << inputFile << std::endl;
    std::cout << outputFile << std::endl;*/

    /*LevelBoss *testGoomba = new LevelBoss(0,0,0);   
    std::cout << testGoomba->getDisplayCharacter() << std::endl;
    std::cout << testGoomba->getwinPercent() << std::endl;
    delete testGoomba;*/
}
