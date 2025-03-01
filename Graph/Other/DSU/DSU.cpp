#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

class DSU
{
    private:
    vector<int> vRank, vParent, vSize;

    public:

    DSU(int n)
    {
        vRank.resize(n+1, 0);
        vSize.resize(n+1, 1);
        vParent.resize(n+1, 0);
        for (int i=0; i<=n; ++i)
        {
            vParent[i] = i;
        }
    }

    int findUParent(int iNode)
    {
        if (vParent[iNode] == iNode) {
            return iNode;
        }

        return vParent[iNode] = findUParent(vParent[iNode]);
    }

    void unionByRank(int iNode1, int iNode2)
    {
        int iUParent1 = findUParent(iNode1);
        int iUParent2 = findUParent(iNode2);
        
        if (iUParent1 == iUParent2) {
            return;
        }
        if (vRank[iUParent1] < vRank[iUParent2]) {
            vParent[iUParent1] = iUParent2;
        }
        else if (vRank[iUParent2] < vRank[iUParent1]) {
            vParent[iUParent2] = iUParent1;
        }
        else {
            vParent[iUParent2] = iUParent1;
            ++vRank[iUParent1];
        }
        cout<< "\nParent: ";
        for (auto iVal:vParent) { cout << iVal << " "; }
        cout<<"\n";
    }

    void unionBySize(int iNode1, int iNode2)
    {
        int iUParent1 = findUParent(iNode1);
        int iUParent2 = findUParent(iNode2);
        
        if (iUParent1 == iUParent2) {
            return;
        }
        if (vSize[iUParent1] < vSize[iUParent2]) {
            vParent[iUParent1] = iUParent2;
            vSize[iUParent2] += vSize[iUParent1];
        }
        else {
            vParent[iUParent2] = iUParent1;
            vSize[iUParent1] += vSize[iUParent2];
        }
        cout<< "\nParent: ";
        for (auto iVal:vParent) { cout << iVal << " "; }
        cout<<"\n";
    } 


    bool isSameComponent(int iNode1, int iNode2) 
    {
        bool bRetVal = false;
        if (findUParent(iNode1) == findUParent(iNode2)) {
            cout << "Nodes "<< iNode1 <<" & " << iNode2 << " are in same component:)\n";
            bRetVal = true;
        }
        else {
            cout << "Nodes "<< iNode1 <<" & " << iNode2 << " are in diffrent component!\n";
            bRetVal = false;
        }
        return bRetVal;
    }

};
    
int main()
{
    
    DSU dsuByRank(7), dsuBySize(7);
    cout << "\nTest case 1 Union By Rank*************************************\n\n";
    dsuByRank.unionByRank(1, 2);
    dsuByRank.unionByRank(2, 3);
    dsuByRank.unionByRank(4, 5);
    dsuByRank.unionByRank(6, 7);
    dsuByRank.unionByRank(5, 6);

    dsuByRank.isSameComponent(3, 7);
    cout << "Connected 3 & 7:)\n";
    dsuByRank.unionByRank(3, 7);

    dsuByRank.isSameComponent(3, 7);


    
    cout << "\n\n\nTest case 1 Union By Size*************************************\n\n";
    dsuBySize.unionByRank(1, 2);
    dsuBySize.unionByRank(2, 3);
    dsuBySize.unionByRank(4, 5);
    dsuBySize.unionByRank(6, 7);
    dsuBySize.unionByRank(5, 6);

    dsuBySize.isSameComponent(3, 7);
    cout << "Connected 3 & 7:)\n";
    dsuBySize.unionByRank(3, 7);

    dsuBySize.isSameComponent(3, 7);


    
    return 0;
}