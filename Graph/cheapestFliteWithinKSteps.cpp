//GFG: Cheapest Flights Within K Stops
//LINK:  https://bit.ly/3UIneer

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        //generate graph from matrix
        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        //distance vector
        vector<int> dis(n, 1e9);
        
        //queue structure {stop, {node, dis}}
        queue<pair<int, pair<int, int>>>q;
        
        //push source node
        q.push({0,{src,0}});
        
        //distance to src is always zero
        dis[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int wt=it.second.second;
            
            //traverse it's neighbour node
            for(auto it:adj[node]){
                int adjNode=it.first;
                int dist=it.second;
                
                //when stop becomes greater than K then we don't need to calculate further
                //Since, our aim is to reach within K stops not more than that
                if(stop>K) continue;
                if(wt+dist<dis[adjNode] && stop<=K){
                    dis[adjNode]=wt+dist;
                    q.push({stop+1, {adjNode, dis[adjNode]}});
                }
            }
        }
        
        //if unreachable
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }

//TC: O(E)~ O(N) Since we are using queue and here total no of edges is equal to size of flights
//SC: O(N)
