#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s)
        {
		    int iSize = s.size();
            int iPower = (1<<iSize);
            vector<string> vAns;
            for(int iIdx=1; iIdx < iPower; iIdx++)
            {
                int iPos = 0;
                int iVal = iIdx;
                string sStr = "";
                while (iVal)
                {
                    if(iVal&1)
                    {
                        sStr += s[iPos];
                    }
                    iVal = iVal>>1;
                    iPos++;
                }
                vAns.push_back(iPos);
            }

            sort(vAns.begin(), vAns.end());
            return vAns;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends 


    
int main()
{
    lli T; cin>>T;
    while(T--)
    {
        
    }
    
    return 0;
}