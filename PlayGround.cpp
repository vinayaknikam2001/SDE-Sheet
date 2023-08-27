#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;


int lengthOfLongestSubstring(string s) 
{
    int n = s.size();
    int maxLen = 0, len = 0;
    map<char, int> subMap;

    for (int i=0; i<n; ++i)
    {
        if (subMap.find(s[i]) == subMap.end())
        {
            subMap[s[i]] = i;
            ++len;
        }
        else
        {
            len = i - subMap[s[i]];
            subMap[s[i]] = i;
        }
        maxLen = max(maxLen, len);
        
    }

    return maxLen;
}

int main()
{

    vector<int> v = {1, 0, -1, 0, -2, 2};
    fourSum(v, 0);
    return 0;
}