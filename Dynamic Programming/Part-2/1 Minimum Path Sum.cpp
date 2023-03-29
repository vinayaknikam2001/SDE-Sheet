// https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Self Solved
#include <bits/stdc++.h>

int func(int idx1, int idx2, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    if(idx1 == (m-1) && idx2 == (n-1))
        return grid[idx1][idx2];
    if(dp[idx1][idx2] != -1e7)
        return dp[idx1][idx2];

    int path1 = INT_MAX, path2 = INT_MAX;

    if(idx1 < (m-1))
        path1 = grid[idx1][idx2] + func(idx1+1, idx2, grid, m, n, dp);
    if(idx2 < (n-1))
        path2 = grid[idx1][idx2] + func(idx1, idx2+1, grid, m, n, dp);
    
    return dp[idx1][idx2] = min(path1, path2);
}

int minSumPath(vector<vector<int>> &grid) 
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1e7));
    return func(0, 0, grid, m, n, dp);
}
