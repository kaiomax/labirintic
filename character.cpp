#include <iostream>
#include "tile.h"
#include "board.h"
#include "character.h"

Character::Character(Board * board, int row, int col) {
    this -> board = board;
    this -> position.row = row;
    this -> position.col = col;
    this -> setPosition();
}

void Character::move(char direction) {
    this -> lockPosition();
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
    this -> board -> tile(position.row, position.col) -> setType(Tile::ALFA);
}

void Character::lockPosition() {
    this -> board -> tile(position.row, position.col) -> setType(Tile::LOCKED);
}
