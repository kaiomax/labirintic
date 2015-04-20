#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "utils.h"
#include "tile.h"
#include "board.h"
using namespace std;
using namespace constants;

Board::Board() {
    this -> tiles = new Tile * [BOARD_ORDER];

    for (int i = 0; i < BOARD_ORDER; ++i)
        this -> tiles[i] = new Tile[BOARD_ORDER];
};

void Board::draw() {
    float ratio = ( 700 / BOARD_ORDER );

    for (int i = 0; i < BOARD_ORDER; ++i)
        for (int j = 0; j < BOARD_ORDER; ++j)
            al_draw_filled_rectangle(ratio*j, ratio*i, ratio*(1+j), ratio*(i+1), this -> tiles[i][j].color());
}

Tile * Board::tile(int row, int col) {
    return &this -> tiles[row][col];
}
