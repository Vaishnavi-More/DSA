//GFG: Strongly Connected Components (Kosaraju's Algo)
//LINK: https://bit.ly/3R6LzID

/*Strongly Connected Components: This are such components where there is path from one node to all other node. Simply, cycle is present*/

/*Intution: If we reverse the edges between the SCC then we can get the total no of SCC's and can also print them*/

/*Kosaraju's Algo: Only applicable for DAG 
  1) Store the start time in a stack using DFS traversal
  2) Reverse the edges to disconnect path from one Strongly connected components to another.
  3) Do DFS traversal
*/

//Code:

private:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, stack<int> &s){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, s);
            }
        }
        s.push(node);
    }
   void dfs3(int node, vector<int>adjT[], vector<int>&vis){
        vis[node]=1;
        for(auto it: adjT[node]){
            if(!vis[it]){
                dfs3(it, adjT, vis);
            }
        }
    }
  public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack <int>s;
        vector<int> vis(V, 0);
        
        //store start time
        //O(V+E)
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, s);
            }
        }
        vector<int>adjT[V];
        
        //reverse graph edges
        //O(V+E)
        for(int i=0; i<V; i++){
            vis[i]=0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        //do DFS traversal
        //O(V+E)
        int cnt=0;
        while(!s.empty()){
           int node= s.top();
           s.pop();
            if(!vis[node]){
                cnt++;
                dfs3(node, adjT, vis);
            }
        }
        return cnt;
    }

//TC: O(V+E) + O(V+E)  + O(V+E)~  O(V+E)
//SC: O(V)+O(V)+O(V+E)   where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.
