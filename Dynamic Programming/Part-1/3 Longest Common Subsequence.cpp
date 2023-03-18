//https://www.codingninjas.com/codestudio/problems/624879?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//Self Solved
#include <bits/stdc++.h>
using namespace std;

int func(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i1<0 || i2<0)
        return 0;
    if(dp[i1][i2] != INT_MIN)
        return dp[i1][i2];
    
    if(s1[i1] == s2[i2])
        return dp[i1][i2] =  1 + func(i1-1, i2-1, s1, s2, dp);
    else
        return dp[i1][i2] = max(func(i1-1, i2, s1, s2, dp), func(i1, i2-1, s1, s2, dp));
}

int lcs(string s, string t)
{
    int n1 = s.size(), n2 = t.size();
    vector<vector<int>> dp(n1,vector<int>(n2, INT_MIN));
	return func(n1-1, n2-1, s, t, dp);
}