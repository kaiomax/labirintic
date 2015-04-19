#ifndef _LABYTINTH_H_
#define _LABYTINTH_H_

class Labyrinth {
public:
    Labyrinth(int alfa[], int omega[], int amount, int (*list)[2]);
    int amount;
    struct Position {
        int row, col;
    } alfa, omega;
    Position * walls;

private:
    int (*wallsList)[2];

    void setWalls();
};

#endif
