// LeetCode = https://leetcode.com/problems/merge-sorted-array/
// Brute-Force = self
// Optimal = Referenced

/*########################-------Brute-Force---------###############################*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    vector<int> tmp(m,0);
    int i=0;
    for(auto &e:tmp)
        {e = nums1[i]; ++i;}
    
    int iPt1 = 0, iPt2 = 0;
    i=0;
    while (iPt1 < m && iPt2 < n)    
    {
        if(tmp[iPt1] < nums2[iPt2])
        {
            nums1[i] = tmp[iPt1]; ++iPt1;
        }
        else
        {
            nums1[i] = nums2[iPt2]; ++iPt2
        }
        ++i;
    }

    if(iPt1>=m)
    {
        while(iPt2<n)
        {
            nums1[i] = nums2[iPt2];
            ++iPt2; ++i;
        }
    }
    if(iPt2>=n)
    {
        while(iPt1<m)
        {
            nums1[i] = tmp[iPt1];
            ++iPt1; ++i;
        }
    }
    
}

/*###########################----Optimal Approach-----#########################*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int iSize = m+n;
    for(int i=m, j=0; i<iSize; ++i, ++j)
        nums1[i] = nums2[j];
    
    int iSeal = (iSize/2)+(iSize%2);
    while (iSeal>0)
    {
        int iLeft = 0; int iRight = iLeft + iSeal;
        while (iRight < iSize)
        {

            if(nums1[iLeft] > nums1[iRight])
            {
                swap(nums1[iLeft], nums1[iRight]);
            }
            ++iRight; ++iLeft;
        }
        if(iSeal==1) break;
        iSeal = (iSeal/2)+(iSeal%2);
    }
    
}