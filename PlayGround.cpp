#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;


class Singleton
{
private:

    Singleton(){}
    ~Singleton(){}
public:
    Singleton(const Singleton &objSingleton) = delete;
    Singleton operator=(const Singleton &objSingleton) = delete;

    static Singleton& getInstance() 
    {
        static Singleton objSingleton;
        return objSingleton;
    }

};


    
int main()
{
    Singleton &obj = Singleton::getInstance();
    cout<<"Success!";
    return 0;
}