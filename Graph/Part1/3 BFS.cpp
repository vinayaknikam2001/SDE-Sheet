// GFG Link = https://www.geeksforgeeks.org/problems/topological-sort/1
// Self solved...


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        bool bVisited[V] = {0};
        vector<int> res;
        queue<int> q;
        q.push(0);
        bVisited[0] = true;
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
/* Don't mark element visited here mark moment u push
it inside a queue*/
            
            for (int vertex : adj[node])
            {
                if (!bVisited[vertex])
                {
/* Here we had very curcial learning point. Mark that element as visited the moment u push inside 
a queue ...otherwise problem will be faced. Because it's possible that you push same element twice in a queue.*/
                    q.push(vertex);
                    bVisited[vertex] = true;
                }
            }
            
        }
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends