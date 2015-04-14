#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {
public:
    Character(Board * board, int row, int col);
    void move(char direction);
    bool isAlive, isWinner;

private:
    Board * board;
    struct Position {
        int row, col;
    } position;

    void setPosition();
    void lockOldPosition();
};

#endif