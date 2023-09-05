#include "myboard.h"
#include "mytile.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

MyBoard::MyBoard(int dimension)
{
    pointsScoredLastRound = 0;
    tileCollisionLastRound = false;
    this->dimension = dimension;
    init();
}

MyBoard::MyBoard(const MyBoard &other)
{
    dimension = other.dimension;
    init();
    for(int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if(other.board[i][j] == NULL)
                board[i][j] = NULL;
            else
                board[i][j] = new MyTile(*(other.board[i][j]));
        }
    }
}

MyBoard::~MyBoard()
{
    // destroy the tiles
    for(int i = 0; i < dimension; ++i) {
        for(int j = 0; j < dimension; ++j) {
            delete board[i][j];
        }
    }
}


void MyBoard::init()
{
    board.resize(dimension);
    for(int i = 0; i < dimension; ++i)
        board[i].resize(dimension);
    // for loop run through board create tiles
    for (int i = 0; i < dimension; ++i)
        for (int j =0; j < dimension; ++j)
            board[i][j] = NULL;
}

QVector<int> MyBoard::freePosition()
{
    QVector<int> pos;
    if(full()) {
        pos.append(-1);
        pos.append(-1);
    } else {
        int i,j;
        do {
            i = rand()%dimension;
            j = rand()%dimension;
        } while (board[i][j] != NULL);
        pos.append(i);
        pos.append(j);
    }
    return pos;
}


bool MyBoard::changed(MyBoard& other) const
{
    if (dimension != other.dimension)
        return false;
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            if(((board[i][j]== NULL && other.board[i][j] != NULL) ||
                 (board[i][j] != NULL && other.board[i][j] == NULL)) ||
                ((board[i][j] != NULL && other.board[i][j] != NULL) &&
                   board[i][j] -> getValue() != other.board[i][j] -> getValue()))
                return true;
    return false;
}

void MyBoard::reset()
{
    pointsScoredLastRound = 0;
    tileCollisionLastRound = false;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j)   {
            delete board[i][j];
            board[i][j] = NULL;
        }
    }

    QVector<int> start = freePosition();
    board[start[0]][start[1]] = new MyTile();
    start = freePosition();
    board[start[0]][start[1]] = new MyTile();

}

MyTile* MyBoard::getTile(int i, int j)
{
    return board[i][j];
}

void MyBoard::move(Direction direction)
{
    MyBoard pre_move_board(*this);
    prepareForNextMove();

    switch (direction) {
    case Up:
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                moveVertically(i, j, Up);
        break;
    case Down:
        for (int i = dimension-1;i >= 0; --i)
            for (int j = 0; j < dimension; ++j)
                moveVertically(i, j, Down);
        break;
    case Left:
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                moveHorizontally(i, j, Left);
        break;
    case Right:
        for (int i = 0; i < dimension; ++i)
            for (int j = dimension-1; j >=0; --j)
                moveHorizontally(i, j, Right);
    }

    // if the board has changed (and there was no tile collision), place a new tile
    if(changed(pre_move_board)/*&& !tileCollisionLastRound*/) {
        QVector<int> newpos = freePosition();
        board[newpos[0]][newpos[1]] = new MyTile();
    }

    notificateObserver();
}

void MyBoard::prepareForNextMove()
{
    tileCollisionLastRound = false;
    pointsScoredLastRound = 0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if(board[i][j] != nullptr) {
                board[i][j] -> setUpgratedThisMove(false);
            }
        }
    }
}

bool MyBoard::movePossible() const
{
    if(full()) {
        // check if there s still a move to do
        MyBoard newMyBoard(*this);
        newMyBoard.move(Up);
        if(changed(newMyBoard)) return true;
        newMyBoard.move(Down);
        if(changed(newMyBoard)) return true;
        newMyBoard.move(Left);
        if(changed(newMyBoard)) return true;
        newMyBoard.move(Right);
        if(changed(newMyBoard)) return true;
        // no possible move
        return false;
    } else {
        return true;
    }
}


void MyBoard::moveHorizontally(int i, int j, Direction dir)
{
    if(board[i][j] != NULL) {
        bool tileCollision = false;
        int newj;
        if(dir == Right)
            newj = j + 1;
        // to the left to the left
        else
            newj = j - 1;

        // while going in dir direction until we encounter or get out of bounds
        while(inbounds(i, newj) && board[i][newj] == NULL) {
            if (dir == Right)
                newj++;
            else
                newj--;
        }

        // out of bounds or ...
        if(!inbounds(i, newj)) {
            if(dir == Right) {
                board[i][dimension -1] = board[i][j];
            } else {
                board[i][0] = board[i][j];
            }
        }
        // ...collision
        else {
            // collision with tile of same value
            if(board[i][newj] -> getValue() == board[i][j] -> getValue() &&
                !board[i][newj] -> getUpgratedThisMove()) {

                tileCollision = true;
                handleCollision(i, newj);
            }
            // collision with tile of other value, put this tile next to it
            else {
                if(dir == Right) {
                    board[i][newj - 1] = board[i][j];
                } else  {
                    board[i][newj + 1] = board[i][j];
                }
            }
        }
        // remove the original tile if we made multiple moves
        // or if we did not make multiple but we merged with the tile we were standing next to
        if((dir == Right && newj - 1 != j) || (dir == Left && newj+1 != j) || tileCollision)
                board[i][j] = NULL;

        if(tileCollision)
                tileCollisionLastRound = true;
    }
}

void MyBoard::moveVertically(int i, int j, Direction dir)
{
    if(board[i][j] != NULL) {
        bool tileCollision = false;
        int newi;
        if (dir == Up)
                newi = i - 1;
        // down
        else
                newi = i + 1;

        // keep going in dir direciton until we encounter someting or get out of bounds
        while (inbounds(newi, j) && board[newi][j] == NULL) {
            if (dir == Up)
                newi--;
            else
                newi++;
        }

        // out if bounds or ...
        if(!inbounds(newi, j)) {
            if(dir == Up) {
                board[0][j] = board[i][j];
            } else {
                board[dimension -1 ][j] = board[i][j];
            }
        }
        // ...collision
        else {
            // collision with tile of same value
            if(board[newi][j] -> getValue() == board[i][j] -> getValue() &&
                !board[newi][j] -> getUpgratedThisMove()) {
                tileCollision = true;
                handleCollision(newi, j);
            }
            // collision with tile of other value, put this tile next to it
            else {
                if (dir == Up) {
                    board[newi + 1][j] = board[i][j];
                } else {
                    board[newi - 1][j] = board[i][j];
                }
            }
        }
        // remove the original tile if we make multiple moves
        // or if we did not multiple moves but we merged with the tile we were standing next to
        if((dir == Up && newi+1 != i) || (dir == Down && newi - 1 != i) || tileCollision) {
            board[i][j] = NULL;
        }

        if (tileCollision) {
            tileCollisionLastRound = true;
        }
    }
}

void MyBoard::handleCollision(int i, int j)
{
    board[i][j] -> upgrade();
    board[i][j] -> setUpgratedThisMove(true);
    pointsScoredLastRound += board[i][j] -> getValue();
}

bool MyBoard::full() const
{
    bool full = true;
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            if (board[i][j] == NULL)
                full = false;
    return full;
}

bool MyBoard::inbounds(int i, int j)
{
    return (i >= 0 && j >= 0 && i < dimension && j < dimension);
}
