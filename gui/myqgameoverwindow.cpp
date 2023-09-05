#include "myqgameoverwindow.h"
#include "myqresetbutton.h"

#include <QVBoxLayout>
#include <QLayout>
#include <QDebug>
#include <QResizeEvent>

MyQGameOverWindow::MyQGameOverWindow(QWidget *parent)
    : QWidget{parent}
{
    setStyleSheet("QGameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425, 205);
    QVBoxLayout *layout = new QVBoxLayout(this);
    // game over label
    QLabel* gameover = new QLabel("Game Over!", this);
    gameover->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;}");
    // reset button
    restButton = new MyQResetButton(this);
    restButton->setFixedHeight(50);
    restButton->setFixedWidth(100);
    // add game over label to window
    layout->insertWidget(0, gameover, 0, Qt::AlignCenter);
    // add reset button to window
    layout->insertWidget(1, restButton, 0, Qt::AlignCenter);
}

MyQResetButton* MyQGameOverWindow::getRestButton() const
{
    return restButton;
}
