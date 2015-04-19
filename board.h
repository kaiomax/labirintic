#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:
    Board(int rows, int cols, Labyrinth * labyrinth);
    void draw();
    Tile * tile(int row, int col);
    int rows, cols;
    Labyrinth * labyrinth;
    void initialize();

private:
    Tile ** tiles;
};

#endif
