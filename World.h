#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Level.h"
#include "Mario.h"
using namespace std;

class World {
    private:
        int total_levels; //variable for total number of levels
        Level **levels; //array that will hold all the levels
        void initializeWorld(); //fills in the level array with levels
        int dimension; //variable for the dimensions of the grid
        int coin_percentage; //variable for coin percentage within the grid
        int nothing_percentage; //variable for nothing percentage within the grid
        int goomba_percentage; //variable for goomba percentage within the grid
        int koopa_percentage; //variable for koopa percentage within the grid
        int mushroom_percentage; //variable for mushroom percentage within the grid
        Mario *mario;
    public: 
        World(); //default constructor
        World(int num_levels, int level_size, int cp, int np, int gp, int kp, int mp); //overloaded constructor

        void addMario(Mario* mario); //passing in Mario to the World
        void placeMarioInWorld(); //places mario in the world
        void updateMarioInWorld(Mario* mario); //updates the world to refelct mario's position/changes
        ~World();
        void printWorld(); //prints out all the levels in world
        void outputWorld(ofstream& output); //outputs all the levels in world to outputFile

};

#endif