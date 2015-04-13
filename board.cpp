#include <iostream>
#include <cstdlib>
#include "tile.h"
#include "board.h"
using namespace std;

Board::Board(int rows, int cols) {
    this -> rows = rows;
    this -> cols = cols;
    this -> tiles = new Tile * [rows];

    for (int i = 0; i < rows; ++i)
        this -> tiles[i] = new Tile[cols];

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            this -> tiles[i][j].setType(Tile::DEFAULT);
};


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

void Board::setLabyrinth(int (*array)[2], int length) {
    for (int i = 0; i < length; ++i)
        this -> tile(array[i][0], array[i][1]) -> setType(Tile::WALL);
}
