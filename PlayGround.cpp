#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;


    bool isPal(string s, int st, int end, vector<vector<short>>&dp)
    {
        if (st >= end)
            return true;

        if (dp[st][end] != -1)
            return dp[st][end];

        if (s[st] == s[end])
        {
            return dp[st][end] = isPal(s, st+1, end-1, dp);
        } 
        else 
        {
            return dp[st][end] = false;
        }

    }

    string longestPalindrome(string s) 
    {
        int n = s.size();
        vector<vector<short>> dp(n+1, vector<short>(n+1,-1));
        int st = 0, size = 1, maxLen = 1;

        for (int i=0; i<n; ++i)
        {
            for (int j=i+1; j<n; ++j)
            {
                int len = j-i+1;
                if (isPal(s, i, j, dp))
                {
                    if (len > maxLen)
                    {
                        maxLen = len;
                        st = i; size = len;
                    }
                }
            }
        }    

        string ans = s.substr(st, size); 
        return ans;
    }
    
int main()
{
    string s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    cout<<s.size();
    
    return 0;
}