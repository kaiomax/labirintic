#include <iostream>
#include <allegro5/allegro.h>
#include "tile.h"
#include "labyrinth.h"
#include "board.h"
#include "character.h"
using namespace std;

Character::Character(Board * board) {
    this -> board = board;
    this -> isWinner = false;
    goToStartPosition();
}

void Character::move(int key) {
    oldPosition = currentPosition;
    newPosition = currentPosition;
    bool validMove = true;

    switch(key) {
        case ALLEGRO_KEY_D:
            newPosition.col++;
            break;
        case ALLEGRO_KEY_S:
            newPosition.row++;
            break;
        case ALLEGRO_KEY_A:
            newPosition.col--;
            break;
        case ALLEGRO_KEY_W:
            newPosition.row--;
            break;
        default:
            validMove = false;
            break;
    }

    if (validMove)
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

    this -> canMove = movesAvailable(currentPosition.row, currentPosition.col);
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

void Character::goToStartPosition() {
    this -> currentPosition.row = this -> board -> labyrinth -> alfa.row;
    this -> currentPosition.col = this -> board -> labyrinth -> alfa.col;
}
