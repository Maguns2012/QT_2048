#ifndef MYQGAMEBOARD_H
#define MYQGAMEBOARD_H

#include "core/myobserver.h"
#include "myqgameoverwindow.h"

#include <QVector>
#include <QWidget>

class MyQResetButton;
class MyGame;
class QKeyEvent;
class MyQTile;
class QGridLayout;
class QVBoxLayout;
class QLabel;


class MyQGameBoard : public QWidget,  public MyObserver
{
    Q_OBJECT
public:
    explicit MyQGameBoard(QWidget* parent = 0);
    ~MyQGameBoard();

    void notify();

private:
    MyGame* game;
    // gui repersentation of board
    QVector<QVector<MyQTile *>> gui_board;
    // main layout
    QVBoxLayout *mainLayout;
    // grid layout of board
    QGridLayout *boardLayout;
    // score widget
    QLabel *score;
    // game over widget
    MyQGameOverWindow gameOverWindow;
    // winner widget
    QLabel *winWidget;
    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent *event);
signals:
public slots:
    void resetGame();
};

#endif // MYQGAMEBOARD_H
