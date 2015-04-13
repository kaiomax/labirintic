#include <iostream>
#include <stdio.h>
#include "tile.h"
#include "board.h"
using namespace std;

#define ROWS 14
#define COLS 14

int main() {
    Board board(ROWS, COLS);

    board.tile(0,0) -> setType(Tile::ALFA);
    board.tile(13,13) -> setType(Tile::OMEGA);

    int labyrinthTiles[16][2] = {
        {3,5},{4,5},{5,5},{6,5},{6,6},{6,7},{6,8},{6,9},{6,10},{6,11},
        {6,12},{6,13},{7,7},{8,7},{9,7},{10,7}
    };

    board.setLabyrinth(labyrinthTiles, 16);

    board.draw();


    return 0;
}
