#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;
    
    
long maxPossibleWays(int *den, int i, int iVal, int iSum = 0)
{
    if (0 == iVal)
    {
        return 1;
    }
    if (0 == i)
    {
        return  (0 == iVal%den[i]) ? iVal/den[i] : 0;
    }

    long iPik = 0, iNPik = 0;
    if (den[i] <= iVal)
    {
        iPik = maxPossibleWays(den, i, iVal-den[i]);
    }
    iNPik = maxPossibleWays(den, i-1, iVal);

    return (iPik + iNPik);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return maxPossibleWays(denominations, n-1, value);
}