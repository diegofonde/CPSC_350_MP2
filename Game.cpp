#include "Game.h"

Game::Game(std::string inputFile, std::string outputFile){
    //TODO: create world mario variables

    processFile(inputFile);
    gameOver = false;

    mario = new Mario(V);
    world = new World(L, N, coinPercent, blankPercent, goombaPercent, koopaPercent, mushroomPercent);
}

Game::~Game(){
    //TODO: delete mario
    delete world;
    delete mario;
}

void Game::runGame(){
    world->printWorld();
    mario->placeMario(N);
    world->addMario(mario);
    world->updateMarioInWorld(mario);
    while (!isGameOver()){
        mario->move(N);
        //std::cout << "Mario Level: " << mario->getLevel() << std::endl;
        world->updateMarioInWorld(mario);
        //std::cout << "Mario Level: " << mario->getLevel() << std::endl;
    }
    //world->printWorld();
    //add mario to world

    //loop:
    //mario interacts, loop for repeated interaction inside level
    //mario moves
    //update level to reflect mario moving
    //check for gameOver

    //TODO: implement game loop
}

bool Game::isGameOver(){
    if (mario->getLives() <= 0){
        std::cout << "mario lost" << std::endl;
        return true;
    }
    else if (mario->getLevel() > L-1){
        std::cout << "mario won" << std::endl;
        return true;
    }
    return false;
}

void Game::processFile(std::string inputFile){
    std::string stringContents; //used to move through inputFile
    std::ifstream readFile(inputFile); //opens input file to read from
    int lineNum = 1; //tracks current line of file

    while (std::getline(readFile, stringContents)){
        //std::cout << stringContents << std::endl;

        switch (lineNum){ //assigns proper variable with number based on the line
            case 1:
                L = stoi(stringContents);
            case 2:
                N = stoi(stringContents);
            case 3:
                V = stoi(stringContents);
            case 4:
                coinPercent = stoi(stringContents);
            case 5:
                blankPercent = stoi(stringContents);
            case 6:
                goombaPercent = stoi(stringContents);
            case 7:
                koopaPercent = stoi(stringContents);
            case 8:
                mushroomPercent = stoi(stringContents);
            //default:
                //throw error?  
        }

        lineNum++;
    }

    //std::cout << koopaPercent << std::endl;
}

