#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <vector>

class MyObserver;

class MyObject
{
public:
    MyObject();
    void registObserver(MyObserver *ob);
    void notificateObserver();
private:
    std::vector<MyObserver *> observers;
};

#endif // MYOBJECT_H
