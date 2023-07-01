//GFG: Bellman Ford Algorithm
//LINK: https://bit.ly/3K7emug

/*Bellman Ford algo does work similar to Dijkstra.
  It find shortest path from source to all other nodes, just the slight difference in Bellman Ford algo is it can handle negative values.
  Note: Bellman Ford algo finds the shortest path within N-1 iteration only.
*/

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // distance vector
        vector<int>dis(V, 1e8);
        dis[S]=0;
        
        //traverse for n-1 iteration
        for(int i=0; i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                //relaxation of edges
                if(dis[u]!=1e9 && dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        
        //nth traversal to chk if negative cycle is present in graph
        for(auto it: edges){
            int u=it[0];
                int v=it[1];
                int wt=it[2];
                //According to Bellman Ford algo, we will obtain shortes path in n-1 iteration 
                //But as here negative cycle is present distance keep on decreasing
                if(dis[u]!=1e9 && dis[u]+wt<dis[v]){
                    return {-1};
                }
        }
        
        return dis;
    }

//TC: O(V*E)   ...Since we are doing V-1 iteration and travelling all the edges
//SC: O(V)   ...Distance vector
