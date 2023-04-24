// Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        bool vis[V]={0};
        vis[0]=1;
        queue<int> q;
        
        //push starting node 
        q.push(0);
        vector<int> ans;
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            //print node
            ans.push_back(temp);
            
            //Check neighbour elements of temp into adjacency list
            for(auto it: adj[temp]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
        
        //return bfs traversal of graph
        return ans;
    }

//Time Complexity: O(N+E)   ...as we are traversing all nodes at its adjacent nodes
//Space Complexity: O(3N) ~ O(N)   ...space occupied for queue data structure, visited array and adjacency list
