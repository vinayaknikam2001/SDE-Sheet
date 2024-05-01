#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int maxLen(vector<int>&A, int n)
    {   
        map<int, int> mp;
        int iSize = A.size();
        int iCumSum = 0, iAns = 0, iSubSize = 0;
        
        for (int i=0; i<iSize; ++i)
        {
            iCumSum += A[i];
            
            if (iCumSum == n)
            {
                iSubSize = i+1;    
                iAns = max(iAns, iSubSize);
            }
            {
               //int iRem = iCumSum - n; //If value is not 0;
               //But as value is == 0 we can directly use iCumSum;
               auto mpItr = mp.find(iCumSum);
               if (mpItr != mp.end())
               {
                   int iIdx = mpItr->second;
                   iSubSize = i - iIdx;
               }
               iAns = max(iAns, iSubSize);
            }
            
            if (mp.find(iCumSum) == mp.end())
            {
                mp[iCumSum] = i;
            }
            
        }
        
        return iAns;
    }
};


//{ Driver Code Starts.

int main()
{
    
    vector<int> v = {-1,1,-1,1};
    Solution obj;
    obj.maxLen(v, 4);
    return 0; 
}


