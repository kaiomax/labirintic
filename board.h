#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:
    Board(int rows, int cols);
    void draw();
    Tile * tile(int row, int col);

private:
    int rows, cols;
    Tile ** tiles;
};

#endif
