//GFG: Number of Ways to Arrive at Destination
//LINK:  https://bit.ly/3Aro6Mq

int countPaths(int n, vector<vector<int>>& roads) {
        // Creating an adjacency list for the given graph.
         vector<pair<int, int>> adj[n];
        for (auto it : roads) {
        adj[it[0]].push_back({ it[1], it[2] });
        adj[it[1]].push_back({ it[0], it[2] });
         }
         
         //distance vector
        vector<long long int> dis(n, 1e18); // Use long long int
        
        //to store no of ways to particular node
        vector<int> ways(n, 0);
        
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
        pq.push({ 0,0 });
        dis[0] = 0;
        
        //way to start node is always one
        ways[0] = 1;
        
        //modulus value to avoid interger overflow
        int mod = (int)(1e9 + 7);

     while (!pq.empty()) {
         
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        long long int wt = it.first;
        
        //Traverse it's neighbour nodes
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int dist = it.second;
            
            
            if (wt + dist < dis[adjNode]) {
                dis[adjNode] = wt + dist;
                pq.push({ dis[adjNode], adjNode });
                ways[adjNode] = ways[node];
            }
            
            
            else if (wt + dist == dis[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
    
    }

//TC: O(ElogV)
//SC: O(N)
