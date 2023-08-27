// LeetCode = https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Self


class Solution {
public:
    

int lengthOfLongestSubstring(string s) 
{
    int n = s.size();
    int maxLen = 0;

    for (int i=0; i<n; ++i)
    {
        set<char> subString;
        int len = 0;
        for (int j=i; j<n; ++j)
        {
            subString.insert(s[j]);
            ++len;
            if (len != subString.size())
                break;
            else
                maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}
};