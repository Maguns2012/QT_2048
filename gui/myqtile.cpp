#include "gui/myqtile.h"
#include "core/mytile.h"

#include <QGraphicsDropShadowEffect>
#include <QPalette>

MyQTile::MyQTile(MyTile* tile)
{
    setAlignment(Qt::AlignCenter);
    this->tile = tile;
}

void MyQTile::draw()
{
    if(tile == NULL) {
        setText("");
        setStyleSheet("MyQTile { background-color: rgb(204,192,179); border-radius: 10px; }");
    } else {
        setText(QString::number(tile -> getValue()));
        switch (tile->getValue()) {
        case 2: {
            // 可以设置绘板
//            QPalette palette;
//            palette.setColor(QPalette::Window, QColor(238,228,218));
//            palette.setColor(QPalette::WindowText, QColor(119,110,101));
//            this->setPalette(palette);
            // 可以设置字体
//            QFont font("body", 14);
//            this -> setFont(font);
            // 默认携带MyQTile { ... }，但不生效。删除外包装后就生效了。应该是api差异
//            setStyleSheet("MyQTile { background-color: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            setStyleSheet("background-color: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
            break;
        }
        case 4: {
            setStyleSheet("background-color: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 8: {
            setStyleSheet("background-color: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 16: {
            setStyleSheet("background-color: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 32: {
            setStyleSheet("background-color: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 64: {
            setStyleSheet("background-color: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 128: {
            setStyleSheet("background-color: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 256: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(20);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("background-color: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 512: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(30);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("background-color: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 1024: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(40);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("background-color: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        case 2048: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("background-color: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        default: {
            setStyleSheet("background-color: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt;");
            break;
        }
        }
    }
}
