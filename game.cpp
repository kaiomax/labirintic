#include <iostream>
#include "tile.h"
using namespace std;

int main() {

    Tile * tiles;
    tiles = new Tile[4];

    tiles[0].setType(Tile::DEFAULT);
    tiles[0].getType();
    tiles[1].setType(Tile::WALL);
    tiles[1].getType();
    tiles[2].setType(Tile::ALFA);
    tiles[2].getType();
    tiles[3].setType(Tile::OMEGA);
    tiles[3].getType();

    return 0;
}
