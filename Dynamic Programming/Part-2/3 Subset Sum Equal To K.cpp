// https://www.codingninjas.com/codestudio/problems/1550954?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// One Test Case Remained Due to following wrong code..
/*
short func(int i, int tar,  vector<int> &arr, vector<vector<short>> &dp)
{    
    if(i<0)
        return false;
    if(tar == 0)
        return true;
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int lli;

short func(int i, int tar,  vector<int> &arr, vector<vector<short>> &dp)
{
    
    if(tar == 0)
        return true;

    if(i<=0)
        return (arr[0]==tar);

    if(dp[i][tar] != -1)
        return dp[i][tar];

    bool pik=0, nPik=0;
    nPik = func(i-1, tar, arr, dp);
    if(arr[i] <= tar)
        pik = func(i-1, tar-arr[i], arr, dp);
    
    return dp[i][tar] = (pik|nPik) ? 1:0;
}

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<short>> dp(n, vector<short>(k+1, -1));
    short res = func(n-1, k, arr, dp);
    if(res == 1)
        return true;
    else
        return false;
}