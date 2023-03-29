// https://www.codingninjas.com/codestudio/problems/630471?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Self Solved
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long lli;


lli func(int idx, int *den, int tar, vector<vector<lli>> &dp)
{
   
    if(idx == 0)
    {
        if(tar%den[idx] == 0)
            return 1;
        else 
            return 0;   
    }
    if(dp[idx][tar] != -1)
        return dp[idx][tar];

    lli pik = 0, nPik = 0;
    nPik = func(idx-1, den, tar, dp);
    if(den[idx] <= tar)
        pik = func(idx, den, tar-den[idx], dp);
    
    return dp[idx][tar] = pik+nPik;
    
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<lli>> dp(n, vector<lli>(value+1, -1));
    return func(n-1, denominations, value, dp);
}