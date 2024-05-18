#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

    pair<bool,int> fewestCoins(int i, int amount, vector<int> &coins)
    {
        if (amount == 0) {
            return {true, 0};
        }
        if (i == 0) {
            bool bFound = (amount % coins[i] == 0);
            int count = (bFound) ? (amount/coins[i]) : 0;
            return {bFound, count};
        }

        pair<bool, int> pikAmount = {false, 0}, nPikAmount = {false, 0};
        
        if (amount >= coins[i]) {
            pikAmount = fewestCoins(i, (amount-coins[i]), coins);
            if (pikAmount.first) ++pikAmount.second;
        }
        nPikAmount = fewestCoins(i-1, amount, coins);
        if (nPikAmount.first) ++nPikAmount.second;

        if (pikAmount.first && nPikAmount.first) {
            if (pikAmount.second < nPikAmount.second) return pikAmount;
            else return nPikAmount;
        }
        else if (pikAmount.first) {
            return pikAmount;
        }
        else if (nPikAmount.first) {
            return nPikAmount;
        }
        else {
            return {false, 0};
        }
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        pair<bool, int> Ans = fewestCoins(coins.size()-1, amount, coins);
        return (Ans.first) ? Ans.second : -1;
    }    
    
int main()
{
    vector<int> v = {1,2,5};
    coinChange(v, 11);
    
    return 0;
}