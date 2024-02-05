// Leet Code = https://leetcode.com/problems/reverse-words-in-a-string/description/
// Self solved...
// Took a lot time for this 42 Mins.

class Solution {
public:
    string reverseWords(string s) 
    {
        stack<char> st;
        int n = s.size();
        string ans;
        bool bAddSpace = false;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i] == ' ')
            {
                bAddSpace = (!st.empty()) ? true : bAddSpace;
                while (!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
                continue;
            }
            if (bAddSpace)
            {
                ans += ' ';
                bAddSpace = false;
            }
            st.push(s[i]);
        }

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};