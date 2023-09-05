#include "myqgameboard.h"
#include "core/myboard.h"
#include "core/mygame.h"
#include "gui/myqtile.h"
#include "core/mytile.h"
#include "gui/myqresetbutton.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QString>

MyQGameBoard::~MyQGameBoard()
{
    delete game;
}

MyQGameBoard::MyQGameBoard(QWidget *parent): QWidget(parent)
{
    // set default size
    resize(650,450);

    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // will be created in drawboard()
    boardLayout = NULL;

    // create the game and register as observer
    game = new MyGame(4);
    game -> registObserver(this);

    // create the gui board and draw it
    gui_board.resize(game -> getGameBoard() -> getDimension());
    for (int i = 0; i < game -> getGameBoard() -> getDimension(); ++i)
        gui_board[i].resize(game->getGameBoard() -> getDimension());
    for (int i = 0; i < game -> getGameBoard() -> getDimension(); ++i)
        for (int j = 0;j < game -> getGameBoard() -> getDimension(); ++j)
            gui_board[i][j] = NULL;
    drawBoard();

    // create the score widget and add it to the board
    score = new QLabel(QString("Score: %1").arg(game->getScore()));
    score -> setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score -> setFixedHeight(50);
    mainLayout -> insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("QGameBoard { background-color: rgb(187,173,160) }");

    connect(gameOverWindow.getRestButton(), SIGNAL(clickAction()), this, SLOT(resetGame()));
}

void MyQGameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event -> key()) {
    case Qt::Key_Up:
        game -> move(Up);
        break;
    case Qt::Key_Left:
        game -> move(Left);
        break;
    case Qt::Key_Right:
        game -> move(Right);
        break;
        case Qt::Key_Down:
        game -> move(Down);
        break;
    }
}

void MyQGameBoard::notify()
{
    if(game -> isGameOver())
        gameOverWindow.show();
    if(game -> won())
        score -> setText(QString("You hit 2048, congratulations! Keep playing to increase your score.\t\t SCORE: %1").arg(game->getScore()));
    else
        score -> setText(QString("SCORE: %1").arg(game->getScore()));

    drawBoard();
}

void MyQGameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < game -> getGameBoard() -> getDimension(); ++i) {
        for (int j = 0; j < game -> getGameBoard() -> getDimension(); ++j) {
            delete gui_board[i][j];
            gui_board[i][j] = new MyQTile(game -> getGameBoard() -> getTile(i, j));
            boardLayout -> addWidget(gui_board[i][j], i ,j);
            gui_board[i][j] -> draw();
        }
    }
    mainLayout -> insertLayout(0, boardLayout);
}

void MyQGameBoard::resetGame()
{
    game -> restart();
    drawBoard();
    score -> setText(QString("SCORE: 1%").arg(game -> getScore()));
    gameOverWindow.hide();
}
