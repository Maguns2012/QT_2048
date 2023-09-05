#include "myobject.h"
#include "myobserver.h"

MyObject::MyObject()
{

}

void MyObject::notificateObserver()
{
    for (MyObserver* observer : observers)
        observer->notify();
}

void MyObject::registObserver(MyObserver* ob)
{
    observers.push_back(ob);
}
