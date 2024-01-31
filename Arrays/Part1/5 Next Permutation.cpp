//https://www.codingninjas.com/codestudio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
//Referenced
//DSA sheet Arrays Doc (Next Permutation)
/*Approach
Find peak element from last which is max in ascending order then
reverse the array to get next possible list element
*/
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int peak=-1, siz=n-1;
    while(siz>0)
    {
        if(permutation[siz-1] < permutation[siz])
        {
            peak=siz; break;
        }
        siz--;
    }
    int near=0; n--;
    if(peak != -1)
    {
        while(n>=peak)
        {
            if(permutation[n]>permutation[peak-1])
            {
                near=n; break;
            }
            n--;
        }
    }
    else
    {
        reverse(permutation.begin(), permutation.end());
        return permutation; 
    }
    swap(permutation[near], permutation[peak-1]);
    reverse(permutation.begin()+peak, permutation.end());

    return permutation;
}


//Inbuilt C++ Method For this one
next_permutation(permutation.begin(), permutation.end());