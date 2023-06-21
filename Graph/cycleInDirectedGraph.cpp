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

//Using BFS technique [Kahn's Algorithm]

/* Kahn's algo is only applicable for DAG.
It get terminated if DCG is present as a result sorting for all the element can't be obtain.
This indicate cycle is present in a graph
*/

 bool isCyclic(int V, vector<int> adj[]) {
//create indegree array
	    int indg[V]={0};
	    
	    //traverse to calculate indegree
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i]){
	            indg[it]++;
	        }
	    }
	    
	    //create queue for BFS traversal 
	    queue<int> q;
	    
	    //Push node having indegree 0
	    for(int i=0; i<V; i++){
	        if(indg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //create vector to store sorting 
	    vector<int> topo;
	    
	    //traverse until queue becomes empty
	    while(!q.empty()){
	        
	        //store node into vector
	        int temp=q.front();
	        q.pop();
	        topo.emplace_back(temp);
	        
	        //traverse it's neighbour node and decrement neighbour node's indegree
	        for(auto it: adj[temp]){
	            indg[it]--;
	            
	            //if indegree of neighbour node become 0 than it is ready to insert into queue
	            if(indg[it]==0){
	                q.push(it);
	            }
	        }
	    }

        //if size of topo is equal to V than this indicate cycle is not present 
        if(topo.size()==V) return false;
        //else present
        return true;
 }


//TC: O(N)+O(N+E) ~ O(N+E)
//SC: O(N)
