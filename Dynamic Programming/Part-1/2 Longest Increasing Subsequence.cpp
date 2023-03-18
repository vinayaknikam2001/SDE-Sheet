//https://www.codingninjas.com/codestudio/problems/630459?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//Referenced
/*
	As DP will be generated for a respective [idx] and [prev];
	and prev can be -ve so we are storing in +1 format in DP.
*/
#include <bits/stdc++.h>
using namespace std;

int func(int idx, int arr[], int prev, vector<vector<int>> &dp, int siz)
{
    if(idx == siz)
        return 0;
    if(dp[idx][prev+1] != INT_MIN)
        return dp[idx][prev+1];

    int pik=0, nPik=0;
    if(prev == -1 || arr[idx] > arr[prev])
        pik = 1 + func(idx+1, arr, idx, dp, siz);
    nPik = 0 + func(idx+1, arr, prev, dp, siz);

    return dp[idx][prev+1] = max(pik, nPik);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
    return func(0, arr, -1, dp, n);
}
