#include <bits/stdc++.h>
using namespace std;


class Solution {

    string getRLE(string& s)
    {
        int numMap[10] = {0};
        string res = "";
        for (int i=0; i<s.size(); ++i)
        {
            ++numMap[(s[i] - '0')];
        }
        
        for (int i=0; i<10; ++i)
        {
            if (numMap[i])
            {
                res += ('0' + numMap[i]);
                res += ('0' + i);
            }
        }
        return res;
    }
public:
    string countAndSay(int n) 
    {
        //string res = "";
        string sNum = "1";
        for (int i=1; i<=n; ++i)
        {
            sNum = getRLE(sNum);
        }
        return sNum;
    }
};

int main () 
{
    Solution obj;
    obj.countAndSay(4);
    return  0;
}