#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    gameBoard = new MyQGameBoard(this);
    setCentralWidget(gameBoard);
}

MainWindow::~MainWindow()
{
//    delete ui;
    delete gameBoard;
}

