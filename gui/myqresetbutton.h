#ifndef MYQRESETBUTTON_H
#define MYQRESETBUTTON_H

#include <QLabel>

class MyQResetButton : public QLabel
{
    Q_OBJECT
public:
    MyQResetButton(QWidget* parent = 0);

signals:
    void clickAction();
public slots:
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // MYQRESETBUTTON_H
