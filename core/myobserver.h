#ifndef MYOBSERVER_H
#define MYOBSERVER_H


class MyObserver
{
public:
    MyObserver();
    virtual void notify() = 0;
};

#endif // MYOBSERVER_H
