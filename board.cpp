#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "utils.h"
#include "tile.h"
#include "labyrinth.h"
#include "board.h"
using namespace std;
using namespace constants;

Board::Board(int rows, int cols, Labyrinth * labyrinth) {
    this -> rows = rows;
    this -> cols = cols;
    this -> labyrinth = labyrinth;
    this -> tiles = new Tile * [rows];

    for (int i = 0; i < rows; ++i)
        this -> tiles[i] = new Tile[cols];

    initialize();
};

void Board::initialize() {
    int row, col;

    for (int i = 0; i < BOARD_ORDER; ++i)
        for (int j = 0; j < BOARD_ORDER; ++j)
            this -> tiles[i][j].setType(Tile::DEFAULT);

    for (int i = 0; i < ( this -> labyrinth -> amount ); ++i) {
        row = this -> labyrinth -> walls[i].row;
        col = this -> labyrinth -> walls[i].col;

        this -> tile(row, col) -> setType(Tile::WALL);
    }

    this -> tile(this -> labyrinth -> alfa.row, this -> labyrinth -> alfa.col) -> setType(Tile::ALFA);
    this -> tile(this -> labyrinth -> omega.row, this -> labyrinth -> omega.col) -> setType(Tile::OMEGA);
}


void Board::draw() {
    int ratio = ( DISPLAY_SIZE / BOARD_ORDER );

    for (int i = 0; i < BOARD_ORDER; ++i)
        for (int j = 0; j < BOARD_ORDER; ++j)
            al_draw_filled_rectangle(ratio*j, ratio*i, ratio*(1+j), ratio*(i+1), this -> tiles[i][j].color());
}

Tile * Board::tile(int row, int col) {
    return &this -> tiles[row][col];
}
