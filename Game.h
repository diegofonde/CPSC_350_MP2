#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream> 

#include "World.h"
#include "Mario.h"
#include "Mushroom.h"

class Game{
    public:
        Game(std::string inputFile, std::string outputFile); //constructor that takes in inputFile and output File
        ~Game(); //destructor

        void runGame(); //contains main game loop
    
    private:
        void processFile(std::string inputFile); //reads the inputFile and assigns variables
        bool isGameOver(); //returns if the game is over or not
        void updateOutputString(); //updates the outputString
        void clearOutputString(); //clears the outputString

        int L; //number of levels
        int N; //the dimension of the grid
        int V; //the number of initial lives
        int coinPercent; //approximate percent of positions in a level that are coins
        int blankPercent; //aproximate percent of positions in a level that are blank
        int goombaPercent; //aproximate percent of positions in a level that are goombas
        int koopaPercent; //aproximate percent of positions in a level that are koopas
        int mushroomPercent; //aproximate percent of positions in a level that are mushrooms
        bool gameOver; //whether the game is over or not
        World *world; //the world
        Mario *mario; //mario
        std::ofstream writeFile; //the file writer
        std::string outputString; //string to be outputted in the log

};

#endif