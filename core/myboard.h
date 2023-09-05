#ifndef MYBOARD_H
#define MYBOARD_H

#include "myobject.h"

#include <QVector>
#include <QString>

class MyTile;

enum Direction { Up, Down, Left, Right };

class MyBoard : public MyObject
{
public:
    MyBoard(int dimension);
    MyBoard(const MyBoard& other);
    // destroy board
    ~MyBoard();
    // put the board in start state (everything emty except for two 2 tiles)
    void reset();
    MyTile* getTile(int i, int j);
    int getDimension() const { return dimension;}
    void move(Direction direction);
    bool full() const;
    int getPointsScoredLastRound() const { return pointsScoredLastRound; }
    bool isTileCollisionLastRound() const { return tileCollisionLastRound; }
    // is there still a move possible
    bool movePossible() const;
private:
    QVector<QVector<MyTile *> > board;
    int dimension;

    // create an empty board;
    void init();
    // generate a random, free position on the board
    QVector<int> freePosition();
    // return true if the current state of the board is diferent from the argument
    bool changed(MyBoard & other) const;

    bool inbounds(int i, int j);
    // change sate ! ( tileCollision & pointsScoredLastRound)
    void moveHorizontally(int i, int j, Direction direction);
    void moveVertically(int i, int j, Direction direction);
    void handleCollision(int i, int j);

    // some reinitalisation for the round
    void prepareForNextMove();

    int pointsScoredLastRound;
    int tileCollisionLastRound;
};

#endif // MYBOARD_H
