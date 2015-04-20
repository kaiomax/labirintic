#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {
public:
    Character(Board * board);
    void move(int key);
    bool isWinner, canMove;
    void goToStartPosition();

private:
    Board * board;
    struct Position {
        int row, col;
    } currentPosition, oldPosition, newPosition;

    void setPosition();
    bool checkAvailableMove(int row, int col);
    bool movesAvailable(int row, int col);
};

#endif
