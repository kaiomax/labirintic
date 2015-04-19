#include <iostream>
#include <stdio.h>
#include "tile.h"
#include "labyrinth.h"
#include "board.h"
#include "character.h"
using namespace std;

#define ROWS 14
#define COLS 14

int main() {
    int alfa[2] = {2,5};
    int omega[2] = {13,13};
    int labyrinthTiles[16][2] = {
        {3,5},{4,5},{5,5},{6,5},{6,6},{6,7},{6,8},{6,9},{6,10},{6,11},
        {6,12},{6,13},{7,7},{8,7},{9,7},{10,7}
    };

    Labyrinth labyrinth(alfa, omega, 16, labyrinthTiles);
    Board board(ROWS, COLS, &labyrinth);
    Character player(&board);

    char input;

    board.draw();

    while(input != 'q' && !player.isWinner) {
        input = getchar();

        if (input == 's' || input == 'd' || input == 'w' || input == 'a')
            player.move(input);

        if (!player.canMove) {
            board.initialize();
            player.goToStartPosition();
        }

        board.draw();
    }

    if(player.isWinner)
        cout << "Parabéns! Você ganhou!" << endl;

    return 0;
}
