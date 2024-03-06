#ifndef LEVEL_H
#define LEVEL_H

#include <iosteam>
using namespace std;

class Level {
    private: 
        int size;
        char grid*;
    public: 
        Level();
        Level(int level_size);
        ~Level();
        void printLevel;
};

#endif