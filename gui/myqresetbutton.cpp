#include "myqresetbutton.h"

MyQResetButton::MyQResetButton(QWidget * parent): QLabel(parent)
{
    setText("Try Again!");
    setAlignment(Qt::AlignCenter);
    setStyleSheet("MyQResetButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");
}

void MyQResetButton::mousePressEvent(QMouseEvent* event)
{
    emit clickAction();
}
