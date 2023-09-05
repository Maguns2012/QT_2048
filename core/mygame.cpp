#include "mygame.h"
#include "mytile.h"

MyGame::MyGame(int dimension)
{
    score = 0;
    board = new MyBoard(dimension);
    restart();
}

MyGame::~MyGame()
{
    delete board;
}

void MyGame::move(Direction dir) {
    // do the move
    board -> move(dir);

    // update score
    if(board->isTileCollisionLastRound())
        score+= board->getPointsScoredLastRound();

    // if there is no moew ove possible, it's game over
    if(!board->movePossible())
        gameOver = true;

    notificateObserver();
}

void MyGame::restart()
{
    board->reset();
    gameOver = false;
    score = 0;
}

// alernative (and more efficient implementation):
// keep a variable win in board,
// everytime tiles collode check if the upgrade results in a value of Winning_Value
bool MyGame::won() const
{
    for (int i = 0; i < board->getDimension(); ++i)
        for (int j = 0; j < board->getDimension(); ++j)
            if(board->getTile(i,j) != NULL && board->getTile(i,j)->getValue() == Winning_Value)
                return true;
    return false;
}
