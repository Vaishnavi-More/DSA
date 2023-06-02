//GFG: Detect cycle in a directed graph
//Link:  https://bit.ly/3QwPVsi

bool helper(int start,vector<int> adj[], vector<bool>&vis, vector<bool> &pathvis ){
       //DFS Traversal
       
       //mark node as visited 
       vis[start]=1;
       pathvis[start]=1;
       
       //traverse it's neighbour nodes
       for(auto it: adj[start]){
           
           //if neighbour not visited
           if(!vis[it]){
                if(helper(start, adj, vis, pathvis)==true){
                    return true;
                }
           }
           
           //if visted and follows same path 
           else if(pathvis[it]==1) return true;
       }
       
       //backtrack
       pathvis[start]=0;
       return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //visted array
        vector<bool> vis(V, 0);
        
        //pathvisited
        vector<bool> pathvis(V,0);
        
        //traverse graph
        for(int i=0; i<V; i++){
            
            //if node not visted
            if(vis[i]==0){
                if(helper(i, adj, vis, pathvis)) return 1;
            }
        }
        return 0;
        
    }

//TC: O(N)+O(N+E) ~ O(N+E)
//SC: O(N)
