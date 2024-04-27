#include <bits/stdc++.h>
#include <mutex>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

pthread_mutex_t mtxBank;
pthread_mutex_init(&mtxBank);

class BANK
{
private:
    int iBalanceAmt;
    //std::mutex mtxBank;
    //std::condition_variable cvBalance;

public:
    BANK():iBalanceAmt{1000}{}

    void addMoney(unsigned int iAmt)
    {
        //std::unique_lock<mutex> uLock(mtxBank);
        pthread_mutex_lock(&mtxBank);
        iBalanceAmt += iAmt;
        cout<<"Rupees "<<iAmt<<" is added to your account"<<endl;
        checkBalance();
        pthread_mutex_unlock(&mtxBank);
        //cvBalance.notify_one();
    }

    bool isBalance()
    {
        return (iBalanceAmt > 1000) ? true: false;
    }

    void withdrawMoney(unsigned int iAmt)
    {
        //std::unique_lock<mutex> uLock(mtxBank);
        pthread_mutex_lock(&mtxBank);
        auto funcLambda = [&](){return (this->iBalanceAmt > 1000) ? true : false;};
        //cvBalance.wait(uLock, funcLambda);
        
        iBalanceAmt -= iAmt;
        cout<<"Rupees "<<iAmt<<" is removed from your account"<<endl;
        checkBalance();
        pthread_mutex_unlock(&mtxBank);
    }

    unsigned int checkBalance()
    {
        cout<<"Current ACC Balance is:"<<iBalanceAmt<<endl;
        return iBalanceAmt;
    }

};

/*
Ideally it is expected that first money should be added then it should be removed.
If by any chance withdraw money gets called first it will lock the mutex with a unique_lock. Then condtion
variable will check condition if true then it goes ahead otherwise it will unlock unique_lock() and then
wait at that line untill notify is called on same condtion variable. Even if notify called untill the
condition becomes true thread will wait there.
*/
    
int main()
{   
    BANK objBank;
    objBank.checkBalance();
    thread tWithdrawMoney(&BANK::withdrawMoney, &objBank, 500);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    thread tAddMoney(&BANK::addMoney, &objBank, 500);
    

    tAddMoney.join();
    tWithdrawMoney.join();
    objBank.checkBalance();
    
    pthread_mutex_destroy(&mtxBank);
    return 0;
}