//DFS Traversal of Graph

//GFG Link: https://bit.ly/3SocWyX

private:
    void dfs(int node, vector<int> adj[], bool vis[], vector<int>& ans){
        //print node
        ans.push_back(node);
        //mark it as visited node
        vis[node]=1;
        
        //traverse its neighbor nodes 
        for(auto it: adj[node]){
            //check if node is not visited already
            if(!vis[it]){
                //recursive call 
                dfs(it, adj, vis, ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // create visited array
        bool vis[V]={0};
        //create vector to store dfs traversal
        vector<int> ans;
        //As indexing start from 0 thus start node will be 0
        int start=0;
        //Call dfs function
        dfs(start, adj, vis, ans);
        //return ans vector containing dfs traversal
        return ans;
    }

//Time Complexity for undirected graph: O(N)+O(2*E)   ..O(N) for traversal of every node & O(2*E) for traversal of adjacency list
//Time Complexity for directed graph: O(N)+O(E)   ..O(N) for traversal of every node & O(E) for traversal of adjacency list
//Space Complexity:  O(N)+O(N)+O(N) ~ O(N)   ...Space occupied for adjacency list, stack and vector used to store traversal
