// LeetCode = https://leetcode.com/problems/longest-consecutive-sequence/description/
// Self


class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN, iSeqLen = 1;
        if (nums.size() == 0) //To check if array is empty sequence corner case;
        {
            return 0;
        }

        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-1]) // To ignore repeating elements in an array;
                continue;
            if (nums[i] == (nums[i-1]+1))
            {
                iSeqLen++;
            }
            else
            {
                iSeqLen = 1;
            }

            ans = max(ans, iSeqLen);
        }


        return max(ans, iSeqLen); //Necessary when nums.size() == 1 for that taken max():);
    }
};