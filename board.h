#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:
    Board(int rows, int cols);
    void draw();
    Tile * tile(int row, int col);
    void setLabyrinth(int (*array)[2], int length);

private:
    int rows, cols;
    Tile ** tiles;
};

#endif
