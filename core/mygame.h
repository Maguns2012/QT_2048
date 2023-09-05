#ifndef MYGAME_H
#define MYGAME_H

#define Winning_Value 2048

#include "myobject.h"
#include "myboard.h"

class MyBoard;

class MyGame : public MyObject
{
public:
    MyGame(int dimension);
    ~MyGame();
    void restart();
    bool isGameOver() const { return gameOver; }
    MyBoard* getGameBoard() const { return board; }
    void move(Direction dir);
    // return true if the game is in the win state,
    // (i.e. there i a tile that has the value as defined in Winning_Value)
    bool won() const;
    int getScore() const { return score; }
private:
    MyBoard* board;
    bool gameOver;
    int score;
};

#endif // MYGAME_H
