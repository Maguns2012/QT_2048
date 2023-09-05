#ifndef MYQGAMEOVERWINDOW_H
#define MYQGAMEOVERWINDOW_H

#include <QWidget>

class MyQResetButton;

class MyQGameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyQGameOverWindow(QWidget *parent = 0);

    MyQResetButton* getRestButton() const;

signals:

public slots:

private:
    MyQResetButton* restButton;

};

#endif // MYQGAMEOVERWINDOW_H
