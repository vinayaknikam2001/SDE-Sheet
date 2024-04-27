#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;
    
void setZeros(vector<vector<int>> &matrix)
{
    int iRow = matrix.size();
    int iCol = matrix[0].size();

    int arRows[iRow] = {0};
    int arCols[iCol] = {0};

    for (int i=0; i<iRow; ++i)
    {
        for(int j=0; j<iCol; ++j)
        {
            if (matrix[i][j]==0)
            {
                arRows[i] = 1;
                arCols[j] = 1;
            }
        }
    }

    for (int i=0; i<iRow; ++i)
    {
        if (arRows[i])
        {
            for (auto &iVal:matrix[i]) {
                iVal = 0;
            }
        }
    }

    for (int j=0; j<iCol; ++j)
    {
        if (arCols[j])
        {
            for (int i=0; i<iRow; ++i)
            {
                matrix[i][j] = 0;
            }
        }
    }


    
}
    
int main()
{
    lli T; cin>>T;
    
    return 0;
}