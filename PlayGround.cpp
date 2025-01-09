#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) 
    {
        int iRes = 0, iRow = 0, iCol = 0;
        iRow = grid.size ();
        iCol = grid[0].size();
        
        for (int c=0; c<iCol; ++c)
        {
            int iPrev = grid[0][c];
            for (int r=1; r<iRow; ++r)
            {
                if (grid[r][c] <= iPrev)
                {
                    int iVal = (iPrev + 1 - grid[r][c]);
                    iRes += iVal;
                    iPrev = grid[r][c] + iVal;
                }
                else {
                    iPrev = grid[r][c];
                }
            }
        }
        
        
        return iRes;
    }
};

int main () 
{

    Solution obj;
    vector<vector<int>> vec = 
    {
        {3,2},{1,3},{3,4},{0,1}
    };
    cout<<obj.minimumOperations(vec);
    
    return 0;
}