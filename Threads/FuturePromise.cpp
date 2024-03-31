#include <bits/stdc++.h>
using namespace std;

/*
Promise and future is used to achieve sync between 2 threads. Also if there is a
thread which returns some value then it can be sent to another thread. On futSum.get()
thread will be blocked untill that set_value() is called by promise object.
*/


void getSum(std::promise<int>&& promSum, int iVal)
{
    int iSum = 0;
    for(int i=0; i<iVal; ++i)
    {
        iSum += i;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    promSum.set_value(iSum);
    /*
    Here thread might have other tasks to do but once promise.set_value() is called futSum.get()
    will resume it tasks even this threads has further tasks to do :)
    */
}

//This program created to calculate sum of all numbers using promise thread sync.
int main()
{
    int iVal = 1e5;
    std::promise<int> promSum;
    std::future<int> futSum = promSum.get_future();

    std::thread t1(getSum, std::move(promSum), iVal);

    cout<<"Calculating the sum...\n";
    cout<<"Sum is :"<<futSum.get(); // Here

    t1.join();

    return 0;
}
