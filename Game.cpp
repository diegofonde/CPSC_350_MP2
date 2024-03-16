#include "Game.h"

Game::Game(std::string inputFile, std::string outputFile){
    //TODO: create world mario variables

    processFile(inputFile);
    gameOver = false;

    mario = new Mario(V);
    world = new World(L, N, coinPercent, blankPercent, goombaPercent, koopaPercent, mushroomPercent);

    writeFile.open(outputFile);
}

Game::~Game(){
    //TODO: delete mario
    delete world;
    delete mario;
}

void Game::runGame(){
    world->printWorld();
    world->outputWorld(writeFile);
    mario->placeMario(N);
    mario->setTotalLevels(L);

    writeFile << "Mario is starting in position: (" << mario->getLocationX() << ", " << mario->getLocationY() << ")" << endl;
    writeFile << "==========" << endl;
    //updateOutputString();

    world->addMario(mario);

    /*for (int i = 0; i < 20; i++){
        updateOutputString();
        bool marioMoves = world->updateMarioInWorld(mario, writeFile, outputString);
    //TODO: coin not working properly?
    if (marioMoves){
        mario->move(N, outputString);
    }
    writeFile << outputString << endl;
    writeFile << "==========" << endl;
    std::cout << outputString << std::endl;
    clearOutputString();
    }*/
    while (!isGameOver()){
        updateOutputString();
        bool marioMoves = world->updateMarioInWorld(mario, writeFile, outputString);
        if (marioMoves){
            mario->move(N, outputString);
        }
        if (mario->getLevel() > L-1){
            outputString += " MARIO WON THE GAME!";
        }
        else if (!(mario->getLives() > 0)){
            outputString += " Mario has died :(";
        }
        writeFile << outputString << endl;
        writeFile << "==========" << endl;
        clearOutputString();
        //TODO: output world
    }
    writeFile.close();
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
    //else if (mario->getMarioHasWon()){
        //return true;
    //}
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
}

void Game::updateOutputString(){
    outputString += "Level: " + std::to_string(mario->getLevel()) + ".";
    outputString += " Mario is at position (" + std::to_string(mario->getLocationX()) + ", " + std::to_string(mario->getLocationY()) + ").";
    outputString += " Mario is at power level " + std::to_string(mario->getPowerLevel()) + ".";
}

void Game::clearOutputString(){
    outputString = "";
}

