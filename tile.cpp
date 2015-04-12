#include <iostream>
#include "tile.h"
using namespace std;

void Tile::setType(Tile::Type type) {
    _type = type;
}

void Tile::getType() {
    switch(_type) {
        case DEFAULT:
            cout << "." << endl; break;
        case WALL:
            cout << "#" << endl; break;
        case ALFA:
            cout << "o" << endl; break;
        case OMEGA:
            cout << "X" << endl; break;
    }
}
