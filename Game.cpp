#include "Game.h"

Game::Game(std::string inputFile, std::string outputFile){
    //TODO: create world and mario variables

    processFile(inputFile);
    gameOver = false;
}

Game::~Game(){
    //TODO: delete pointers
}

void runGame(){
    //TODO: implement game loop
}

void Game::processFile(std::string inputFile){
    //TODO: process file and assign variables with proper values
    std::string stringContents; //used to move through inputFile
    std::ifstream readFile(inputFile); //opens input file to read from
    int lineNum = 1; //tracks current line of file

    while (std::getline(readFile, stringContents)){
        std::cout << stringContents << std::endl;

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

    std::cout << koopaPercent << std::endl;
}
