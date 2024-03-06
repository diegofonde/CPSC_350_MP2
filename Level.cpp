#include Level.h

Level :: Level() {
    size = 3;
    grid = new char[size][size];
}

Level :: Level(int level_size) {
    size = level_size;
    grid = new char[level_size][level_size];
}