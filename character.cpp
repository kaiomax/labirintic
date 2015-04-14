#include <iostream>
#include "tile.h"
#include "board.h"
#include "character.h"

Character::Character(Board * board, int row, int col) {
    this -> board = board;
    this -> position.row = row;
    this -> position.col = col;
    this -> board -> tile(position.row, position.col) -> setType(Tile::ALFA);
    this -> isAlive = true;
    this -> isWinner = false;
}

void Character::move(char direction) {
    this -> lockOldPosition();
    switch(direction) {
        case 'w':
            this -> position.row--;
            break;
        case 'd':
            this -> position.col++;
            break;
        case 's':
            this -> position.row++;
            break;
        case 'a':
            this -> position.col--;
            break;
    }
    this -> setPosition();
}

void Character::setPosition() {
    Tile * tile;
    Tile::Type tileType;

    if(position.col < 0 || position.row > (this -> board -> rows - 1) || position.col > (this -> board -> cols - 1) || position.row < 0) {
        this -> isAlive = false;
    } else {
        tile = this -> board -> tile(position.row, position.col);
        tileType = tile -> type;

        if (tileType == Tile::WALL || tileType == Tile::LOCKED )
        {
            this -> isAlive = false;
        } else {
            tile -> setType(Tile::ALFA);
        }

        if (tileType == Tile::OMEGA) {
            this -> isWinner = true;
        }
    }
}

void Character::lockOldPosition() {
    this -> board -> tile(position.row, position.col) -> setType(Tile::LOCKED);
}
