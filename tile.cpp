#include <iostream>
#include "tile.h"
using namespace std;

void Tile::setType(Tile::Type type) {
    this->type = type;
}

char Tile::getType() {
    switch(this->type) {
        case DEFAULT:
            return '.';
        case WALL:
            return '#';
        case ALFA:
            return 'o';
        case OMEGA:
            return 'X';
        case LOCKED:
            return '@';
    }
}
