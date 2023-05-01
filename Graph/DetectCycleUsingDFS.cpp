//GFG: Detect cycle in an undirected graph using DFS
//Link:https://bit.ly/3cZMJXp

 bool dfs(int node, int parent, vector<int> adj[], bool vis[]){
      //mark node as visited
      vis[node]=true;
      
      //traverse it's neighbour node
      for(auto it: adj[node]){
          
          //if neighbours not visted
          if(!vis[it]){
              if(dfs(it, node, adj, vis)==true) return true;
          }
          
          //if neighbours are visited & neighbour node is not parent then it indicate cycle is present
          else if(it!=parent){
              return true;
          }
      }
      
      //no cycle is present
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        //create visited array
        bool vis[V]={0};
        
        //traverse vis array 
        for(int i=0; i<V; i++){
            if(!vis[i]){
              if(dfs(i, -1, adj, vis)==true) return true;
            }
        }
        return false;
    }

//Time Complexity: O(N) + O(N+2E) 
//Space Complexity: O(N)+O(N) ~ O(N)
