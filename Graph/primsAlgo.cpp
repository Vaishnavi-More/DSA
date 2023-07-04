//GFG: PRIM'S ALGO
//LINK: https://bit.ly/3ABwwRP

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // visited array
        vector<int> vis(V, 0);
        //priority queue
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //push starting node but don't mark it as visited yet
        pq.push({0, 0});
        //cost of MST
        int sum=0;
        
        //traverse 
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            //if node is already  visted then skip it
            if(vis[node]){
               continue; 
            }
            
            //else
            vis[node]=1;
                sum+=wt;
            //traverse it's adjacent node
            for(auto it: adj[node]){
                int adjNode=it[0];
                int dist=it[1];
                
                //if neighbour node is not visited then push into queue
                if(!vis[adjNode]){
                    pq.push({dist, adjNode});
                }
            }
        }
        
        //cost of mst
        return sum;   
    }

//TC: O(ElogE)+O(ElogE) ~ O(ElogE)  ..where E is the no of iteration and in the worst case all the edges might be stored in pq
//                                    another E is for adjacent node traversal and log E for push operation performed by priority queue

//SC: O(E) + O(V)  ..where E is space required by priority queue & V for visted array 
