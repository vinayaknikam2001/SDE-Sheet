#include <bits/stdc++.h>
#include "ThreadSafeSingleton.h"
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;


Singleton* Singleton::getInstance()
{
    if (Singleton::pObj == NULL)
    {
        Singleton::singleMutex.lock();
        if (Singleton::pObj == NULL)
        {
            Singleton::pObj = new Singleton();
        }
        Singleton::singleMutex.unlock();
    }

    return Singleton::pObj;   
}
    
int main()
{
    Singleton *pObj = Singleton::getInstance();
    Singleton* pObj2 = Singleton::getInstance();

    cout<<"Obj1="<<&pObj<<" Obj2="<<&pObj2<<" EXIT";
    return 0;
}