#include <iostream>
#include <cstdlib>
#include "tile.h"
#include "labyrinth.h"
#include "board.h"
using namespace std;

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

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
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
    system("clear");

    for (int i = 0; i < (this -> rows); ++i) {
        for (int j = 0; j < (this -> cols); ++j) {
            cout << this -> tiles[i][j].getType() << " ";
        }
        cout << endl;
    }
}

Tile * Board::tile(int row, int col) {
    return &this -> tiles[row][col];
}
