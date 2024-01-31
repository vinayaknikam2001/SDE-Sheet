#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;
 

class Solution {
public:
    int maxJump(vector<int>& stones) 
    {
          int max1=INT_MIN, max2=INT_MIN;
          int n = stones.size();
          vector<bool> vis(n,false);
          for(int i=2; i<n; i+=2)
          {
              int cur = abs(stones[i]-stones[i-2]);
              max1 = max(cur, max1);
              if(i != n-1) vis[i] = true;
          }
          if(n%2 == 0){
              max1 = max(max1 ,abs( stones[n-1]-stones[n-2] ));
          }
    
          int pre  = n-1;
          for(int i=n-2; i>=0; i--)
          {
              if(vis[i]) continue;
              int cur = abs(stones[i]-stones[pre]);
              max2 = max(cur,max2);
              pre = i;
          }   
          
          return max(max1, max2);

    }
};