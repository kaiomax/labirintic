#include <iostream>
#include <stdio.h>
#include "tile.h"
#include "board.h"
#include "character.h"
using namespace std;

#define ROWS 14
#define COLS 14

int main() {
    Board board(ROWS, COLS);
    Character player(&board, 5, 0);

    char input;

    int labyrinthTiles[16][2] = {
        {3,5},{4,5},{5,5},{6,5},{6,6},{6,7},{6,8},{6,9},{6,10},{6,11},
        {6,12},{6,13},{7,7},{8,7},{9,7},{10,7}
    };

    board.setLabyrinth(labyrinthTiles, 16);
    board.tile(13,13) -> setType(Tile::OMEGA);

    board.draw();

    while(input != 'q' && player.isAlive && !player.isWinner) {
        input = getchar();

        if (input == 's' || input == 'd' || input == 'w' || input == 'a') {
            player.move(input);
        }

        board.draw();
    }

    if(!player.isAlive) {
        cout << "Você perdeu!" << endl;
    } else if(player.isWinner) {
        cout << "Parabéns! Você ganhou!" << endl;
    }

    return 0;
}
