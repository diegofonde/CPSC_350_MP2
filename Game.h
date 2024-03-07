#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream> 

//#include "World.h"
class Game{
    public:
        Game(std::string inputFile, std::string outputFile); //constructor that takes in inputFile and output File
        ~Game(); //destructor

        void runGame(); //contains main game loop
    
    private:
        void processFile(std::string inputFile); //reads the inputFile and assigns variables

        int *L; //number of levels
        int *N; //the dimension of the grid
        int *V; //the number of initial lives
        int *coinsPercent; //approximate percent of positions in a level that are coins
        int *blankPercent; //aproximate percent of positions in a level that are blank
        int *goombasPercent; //aproximate percent of positions in a level that are goombas
        int *koopasPercent; //aproximate percent of positions in a level that are koopas
        int *mushroomPercent; //aproximate percent of positions in a level that are mushrooms
        bool *gameOver; //whether the game is over or not

        //To Add:
        //Mario *mario;
        //Word *world;
};

#endif