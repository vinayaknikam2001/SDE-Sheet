// LeetCode = https://leetcode.com/problems/find-the-duplicate-number/submissions/
// Normal using hashing could be solved..
// Referenced using floyd warshall's algorithm (Hare & Tortoise)


//Notes for this question = https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/#google_vignette
int findDuplicate(vector<int>& nums) 
{
    int iSlow = 0, iFast = 0;
    do
    {
        iSlow = nums[iSlow];
        iFast = nums[nums[iFast]];
    } while(iSlow != iFast)

    iFast = 0;
    while (iSlow != iFast)
    {
        iSlow = nums[iSlow];
        iFast = nums[iFast];
    }
    
    return nums[iSlow];
}