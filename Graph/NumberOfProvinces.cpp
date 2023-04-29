//GFG: Number of Provinces
//Link: https://bit.ly/3yR3dIB

//Provinces: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

void dfs(int node, bool vis[], vector<int> adjls[]){
      //Depth first search traversal
      //mark visited node 
      vis[node]=1;
      
      //Traverse it's neighbour nodes stored in adjacency list
      for(auto it: adjls[node]){
          if(!vis[it]){
              //recursive call for neighbour node
              dfs(it, vis, adjls);
          }
      }
  }
  
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // create adjacency listy since here matrix is provided to us 
           vector<int> adjls[V];
        //convert matrix into adjacency list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        //create visited array
        bool vis[V]={0};
        
        //create counter to store number of provinces
        int cnt=0;
        
        //traverse visited array
        for(int i=0; i<V; i++){
            if(!vis[i]){
                //call dfs 
                dfs(i, vis, adjls);
                 cnt++;
               
            }
        }
        return cnt;      
    }

//Time Complexity: O(N) + O(V+E)  ...O(N) for outer loop & O(V+E) for dfs traversal
//Space Complexity: O(N)+ O(N) ~ O(N)  ..O(N) for visited array & O(N) for stack
