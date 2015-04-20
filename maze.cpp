#include <iostream>
#include <allegro5/allegro.h>
#include <algorithm>
#include <time.h>
#include "utils.h"
#include "tile.h"
#include "board.h"
#include "maze.h"
using namespace std;
using namespace constants;

Maze::Maze(Board * board) {
    this -> board = board;

    generate();
}

void Maze::generate() {
    int row, col;

    for (int i = 0; i < BOARD_ORDER; ++i)
        for (int j = 0; j < BOARD_ORDER; ++j)
            board -> tile(i, j) -> setType(Tile::WALL);

    // Generate random row and col
    srand (time(NULL));
    row = rand() % BOARD_ORDER;
    col = rand() % BOARD_ORDER;

    alfa.row = row;
    alfa.col = col;
    board -> tile(alfa.row, alfa.col) -> setType(Tile::PATH);

    // Fill maze path from alfa position
    fill(alfa.row, alfa.col);

    // Set ALFA position
    board -> tile(alfa.row, alfa.col) -> setType(Tile::ALFA);

    // Set OMEGA position randomly
    while(board -> tile(row, col) -> type != Tile::PATH) {
        row = rand() % BOARD_ORDER;
        col = rand() % BOARD_ORDER;
    }
    board -> tile(row, col) -> setType(Tile::OMEGA);
}

void Maze::fill(int row, int col) {
    int randDirections[4] = { 1,2,3,4 };
    random_shuffle(&randDirections[0], &randDirections[4]);

    for (int i = 0; i < 4; ++i) {
        switch( randDirections[i] ) {
            case 1: // Up
                if(row - 2 <= 0)
                    continue;
                if(board -> tile(row - 2, col) -> type != Tile::PATH) {
                    setPath(row - 2, col);
                    setPath(row - 1, col);
                    fill(row - 2, col);
                }
                break;
            case 2: // Right
                if(col + 2 >= BOARD_ORDER - 1)
                    continue;
                if(board -> tile(row, col + 2) -> type != Tile::PATH) {
                    setPath(row, col + 2);
                    setPath(row, col + 1);
                    fill(row, col + 2);
                }
                break;
            case 3: // Down
                if(row + 2 >= BOARD_ORDER - 1)
                    continue;
                if(board -> tile(row + 2, col) -> type != Tile::PATH) {
                    setPath(row + 2, col);
                    setPath(row + 1, col);
                    fill(row + 2, col);
                }
                break;
            case 4: // Left
                if(col - 2 <= 0)
                    continue;
                if(board -> tile(row, col - 2) -> type != Tile::PATH) {
                    setPath(row, col - 2);
                    setPath(row, col - 1);
                    fill(row, col - 2);
                }
                break;
        }
    }
}

void Maze::setPath(int row, int col) {
    board -> tile(row, col) -> setType(Tile::PATH);
}

void Maze::restart() {
    Tile * tile;
    Tile::Type tileType;

    for (int i = 0; i < BOARD_ORDER; ++i) {
        for (int j = 0; j < BOARD_ORDER; ++j) {
            tile = board -> tile(i, j);
            tileType = tile -> type;
            if (tileType == Tile::LOCKED || tileType == Tile::ALFA)
            {
                tile -> setType(Tile::PATH);
            }
        }
    }

    board -> tile(this -> alfa.row, this -> alfa.col) -> setType(Tile::ALFA);
}
