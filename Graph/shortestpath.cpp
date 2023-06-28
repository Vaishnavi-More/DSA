//GFG: Shortest Path in Weighted undirected graph
//LINK:  https://bit.ly/3SlYvLp

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //create adjacency list fron matrix
        vector<pair<int, int>>adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // dis vector to store shortest path
        vector<int> dis(n+1, 1e9);
        //parent vector to store parent of  particular node
        vector<int> parent(n+1);
        //initialy store parent of all node as themselves
        for(int i=1; i<=n; i++){
            parent[i]=i;
        }
        //priority queue for Dijkstra traversal
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        //push start node into queue
        pq.push({0,1});
        //distance of source node is always zero
        dis[1]=0;
        
        //traverse
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            
            //traverse it's neighbour node
            for(auto it: adj[node]){
                int adjNode=it.first;
                int dist=it.second;
                if(wt+dist<dis[adjNode]){
                    dis[adjNode]=wt+dist;
                    pq.push({dis[adjNode], adjNode});
                    //mark parent of node
                    parent[adjNode]=node;
                }
            }
        }
        
        //if we cannot reach destination
        if(dis[n]==1e9) return {-1};
        
        //path vector to store path
        vector<int> path;
        int node=n;
        
        //until and unless we reach source node
        while(parent[node]!=node){
            path.push_back(node);
            
            //traverse back to node's parent node
            node=parent[node];
        }
        
        //push source at the end
        path.push_back(1);
        
        //reverse the path since we are storing path from des to src
        reverse(path.begin(), path.end());
        return path;
        
    }

//TC: O(ElogV) + O(N)
//SC: O(N)
