#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;


class ThreadClass
{
    public:
    int iVal;
    void startThread(int iVal)
    {
        this->iVal = iVal;
    }
    static void runThread(int iNum)
    {
        int iVal = iNum;
    }
};

void cFuncThread(int iNum)
{
    int iVal = iNum;
}
    
int main()
{
    int iVal = 0;
    auto lambdaFunc = [&](int iNum)
    {
        iVal = iNum;
    };
    ThreadClass obj;
    thread t_CFuncPtr(cFuncThread, 5);
    thread t_LambdaFunc(lambdaFunc, 10);
    thread t_ClassMethod(&ThreadClass::startThread, &obj, 15);
    thread t_ClassStaticMethod(&ThreadClass::runThread, 20)

    t_CFuncPtr.join();
    t_LambdaFunc.join();
    t_ClassMethod.join();
    t_ClassStaticMethod.join();
    return 0;
}