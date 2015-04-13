#include <iostream>
#include "tile.h"
#include "board.h"
using namespace std;

#define ROWS 14
#define COLS 14

int main() {
    Board board(ROWS, COLS);

    board.tile(0,0) -> setType(Tile::ALFA);
    board.tile(13,13) -> setType(Tile::OMEGA);

    board.tile(3,5) -> setType(Tile::WALL);
    board.tile(4,5) -> setType(Tile::WALL);
    board.tile(5,5) -> setType(Tile::WALL);
    board.tile(6,5) -> setType(Tile::WALL);
    board.tile(6,6) -> setType(Tile::WALL);
    board.tile(6,7) -> setType(Tile::WALL);
    board.tile(6,8) -> setType(Tile::WALL);

    board.draw();

    return 0;
}
