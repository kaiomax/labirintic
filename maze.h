#ifndef _MAZE_H_
#define _MAZE_H_

class Maze {
public:
    Maze(Board * board);
    void generate();
    struct Position {
        int row, col;
    } alfa;
    void restart();

private:
    Board * board;
    void fill(int row, int col);
    void setPath(int row, int col);
};

#endif
