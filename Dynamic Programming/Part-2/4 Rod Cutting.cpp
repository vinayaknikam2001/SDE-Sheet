// https://www.codingninjas.com/codestudio/problems/800284?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Self Solved Wrong ans in sample test because silly mistake of (i-1 in func call...
/*
	nPik = func(i-1, rodSize, price, dp);
    if((i+1) <= rodSize)
        pik = price[i] + func(i-1, rodSize-(i+1), price, dp);
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int lli;

lli func(int i, int rodSize,  vector<int> &price, vector<vector<lli>> &dp)
{
    if(rodSize == 0)
        return 0;

    if(i == 0)
        return rodSize * price[i];
    
    if(dp[i][rodSize] != INT_MIN)
        return dp[i][rodSize];

    int pik = 0, nPik = 0;
    nPik = func(i-1, rodSize, price, dp);
    if((i+1) <= rodSize)
        pik = price[i] + func(i, rodSize-(i+1), price, dp);

    return dp[i][rodSize] = max(pik, nPik);
}

int cutRod(vector<int> &price, int n)
{
    int m = price.size();
    vector<vector<lli>> dp(m, vector<lli>(n+1, INT_MIN));
    return func(m-1, n, price, dp);
}
