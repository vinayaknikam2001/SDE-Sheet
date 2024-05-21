//LeetCode = https://leetcode.com/problems/longest-common-prefix/description/
//Self

class Solution {

    void getFirstCharacter(vector<string>& strs, char &ch, int &i)
    {
        ch = '\0';
        if (i < strs[0].size()) {
            ch = strs[0][i];
        }
    }
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int size = strs.size(), i=0;
        string result = "";
        bool breakLoop = false;

        while (!breakLoop)
        {
            char firstChar;
            getFirstCharacter(strs, firstChar, i);
            for (int j=0; j<size; ++j)
            {
                if (i < strs[j].size()) {
                    breakLoop = (firstChar != strs[j][i]) ? true : false;
                    if (breakLoop) break;
                }
                else {
                    breakLoop = true; 
                    break;
                }
            }
            if (!breakLoop) {
                result += firstChar;
            }
            ++i;
        }

        return result;
    }
};