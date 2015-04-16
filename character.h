#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {
public:
    Character(Board * board, int row, int col);
    void move(char direction);
    bool isWinner, canMove;

private:
    Board * board;
    struct Position {
        int row, col;
    } currentPosition, oldPosition, newPosition;

    void setPosition();
    void lockOldPosition();
    bool checkAvailableMove(int row, int col);
    bool movesAvailable(int row, int col);
};

#endif