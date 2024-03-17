#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "GameObject.h"
#include "GameEnemy.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "LevelBoss.h"
#include "Coin.h"
#include "WarpPipe.h"
#include "Mushroom.h"
using namespace std;

class Level {
    private: 
        int total_levels; //variable for total number of levels
        int dimension; //variable for the dimensions of the grid
        int grid_size; //variable for the area of the grid
        static int level_num; //keeps count of number of level instances
        GameObject ***grid; //variable for the grid that will contain game objects
        int coin_percentage; //variable for coin percentage within the grid
        int nothing_percentage; //variable for nothing percentage within the grid
        int goomba_percentage; //variable for goomba percentage within the grid
        int koopa_percentage; //variable for koopa percentage within the grid
        int mushroom_percentage; //variable for mushroom percentage within the grid
        void initializeGrid(); 
        unsigned int i_random; //variable that will hold the randomized i value that will be assigned to a game object
        unsigned int j_random;//variable that will hold the randomized j value that will be assigned to a game object
        void int_random(); //method that will randomize the i and j values
        Mario *mario;
        // void spawn_object(int num, char c);
    public: 
        Level(); //default constructor
        Level(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp); //overloaded constructor
        ~Level();
        void printLevel(); //prints level
        void outputLevel(std::ofstream& output); //outputs level to file
        void addMario(Mario* mario); //adds mario to the level
        bool updateMarioInLevel(Mario* mario, std::ofstream& output, std::string &outputString); //updates mario's location in the level
        bool marioInteractsInLevel(Mario *mario, GameObject *temp, std::ofstream& output, std::string &outputString); //handles mario's interactions with the object, ensures mario completes interaction
        void clearMarioFromLevel(Mario *mario); //clears mario's space from the level sp mario can move again
        void removeMario(Mario* mario); //removes mario from the level
};

#endif