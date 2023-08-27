// LeetCode = https://leetcode.com/problems/longest-consecutive-sequence/description/
// Self


class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        int iCnt = 0, iMax = 0;
        int n = nums.size();

        for (int i=0; i<n; ++i)
        {
            
            if (i > 0 && (nums[i]-1) == nums[i-1])
            {
                ++iCnt;
            }
            else if (i == 0)
                ++iCnt;
            else if (i > 0 && nums[i] == nums[i-1])
            {
                
            }
            else
            {
                iCnt = 0;
                ++iCnt;
            }
            iMax = max(iMax, iCnt);
            
        }

        return iMax;
    }
};