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
    //std::string inputFile = (std::string)argv[1];
    //std::string outputFile = (std::string)argv[2];

    Game *testGame = new Game("input-spec.txt", "log2.txt");
    //Game *testGame = new Game(inputFile, outputFile);
    testGame->runGame();
    //delete testGame;
}
