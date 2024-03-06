#ifndef WORLD_H
#define WORLD_H

#include <iosteam>
using namespace std;

class World {
    private:
        int total_levels;
        Level* levels;
    public: 
        Level();
        Level(int level_size);

};

#endif