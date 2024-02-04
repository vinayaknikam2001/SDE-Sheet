// LeetCode Link = https://leetcode.com/problems/network-delay-time/submissions/
// Self

int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int, int>>> gList(n+1);
        for(auto v:times){
            gList[v[0]].push_back({v[1], v[2]});
        }
        
        //Greater<> always creates a min Heap & less max-heap 
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
        vector<int> dist(n+1, iMax);
        
        q.push({0, k});
        dist[k] = 0;
        
        while(!q.empty())
        {
            auto vertexPair = q.top();
            int vertexDist = vertexPair.first;
            int vertex = vertexPair.second;
            
            q.pop();
            
            for(auto &nodePair:gList[vertex])
            {
                int node = nodePair.first;
                int nodeDist = nodePair.second;
                
                if((dist[vertex] + nodeDist) < dist[node]){
                    dist[node] = dist[vertex] + nodeDist;
                    q.push({dist[node], node});
                }     
/*The Idea behind this is to keep pushing inside Q until we find out smaller and smaller distances. If we find out smaller we’ll update all node belonging to that vertex */
            }
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == iMax)
                return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
           
    }
