#include "mainwindow.h"

#include <QApplication>
#include "gui/myqgameboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    srand(time(NULL));
    MyQGameBoard board;
    board.show();
//    board.resetGame();
    return a.exec();
}
