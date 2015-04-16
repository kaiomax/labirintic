#include <iostream>
#include "tile.h"
#include "board.h"
#include "character.h"
using namespace std;

Character::Character(Board * board, int row, int col) {
    this -> board = board;
    this -> currentPosition.row = row;
    this -> currentPosition.col = col;
    this -> board -> tile(currentPosition.row, currentPosition.col) -> setType(Tile::ALFA);
    this -> isWinner = false;
}

void Character::move(char direction) {
    oldPosition = currentPosition;
    newPosition = currentPosition;

    switch(direction) {
        case 'w':
            newPosition.row--;
            break;
        case 'd':
            newPosition.col++;
            break;
        case 's':
            newPosition.row++;
            break;
        case 'a':
            newPosition.col--;
            break;
    }

    setPosition();
}

void Character::setPosition() {
    Tile * tile;

    if( checkAvailableMove(newPosition.row, newPosition.col ) ) {
        currentPosition = newPosition;
        tile = board -> tile(newPosition.row, newPosition.col);

        if(tile -> type == Tile::OMEGA)
            isWinner = true;

        tile -> setType(Tile::ALFA);
        board -> tile(oldPosition.row, oldPosition.col) -> setType(Tile::LOCKED);
    }

    canMove = movesAvailable(currentPosition.row, currentPosition.col);
}

bool Character::checkAvailableMove(int row, int col) {
    Tile * tile;
    Tile::Type tileType;

    if( col < 0 || row > (board -> rows - 1) ||
        row < 0 || col > (board -> cols - 1) ) {
        return false;
    } else {
        tile = board -> tile(row, col);
        tileType = tile -> type;

        return tileType != Tile::WALL && tileType != Tile::LOCKED;
    }
}

bool Character::movesAvailable(int row, int col) {
    int moves[4][2] = {
        {row, col + 1},
        {row, col - 1},
        {row + 1, col},
        {row - 1, col}
    };
    int totalMoves = 0;

    for (int i = 0; i < 4; ++i)
        if( checkAvailableMove(moves[i][0], moves[i][1]) )
            totalMoves += 1;

    return totalMoves > 0;
}

void Character::lockOldPosition() {
    board -> tile(currentPosition.row, currentPosition.col) -> setType(Tile::LOCKED);
}
