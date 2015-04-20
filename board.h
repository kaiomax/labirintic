#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
public:
    Board();
    void draw();
    Tile * tile(int row, int col);

private:
    Tile ** tiles;
};

#endif
