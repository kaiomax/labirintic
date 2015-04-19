#include "labyrinth.h"

Labyrinth::Labyrinth(int alfa[], int omega[], int amount, int (*list)[2]) {
    this -> alfa.row = alfa[0];
    this -> alfa.col = alfa[1];
    this -> omega.row = omega[0];
    this -> omega.col = omega[1];
    this -> amount = amount;
    wallsList = list;
    walls = new Position[amount];

    setWalls();
}

void Labyrinth::setWalls() {
    for (int i = 0; i < amount; ++i) {
        walls[i].row = wallsList[i][0];
        walls[i].col = wallsList[i][1];
    }
}
