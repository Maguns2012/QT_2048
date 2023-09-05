#ifndef MYQTILE_H
#define MYQTILE_H

#include <QLabel>

class MyTile;

class MyQTile : public QLabel
{
public:
    MyQTile(const QString & text);
    MyQTile(MyTile* tile);
    void draw();
private:
    MyTile* tile;
signals:
public slots:
};

#endif // MYQTILE_H
