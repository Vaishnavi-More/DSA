//GFG: Shortest path in Directed Acyclic Graph
//Link: https://bit.ly/3dJdQXE

/* Algorithm: 
1) Apply topo Sort
2) Do relaxation of edges
  */

class Solution {
  public:
    void topoSort(int start, vector<pair<int, int>> adj[], stack<int>&s, int vis[]){
        vis[start]=1;
        for(auto it: adj[start]){
            int node=it.first;
            if(!vis[node]){
                topoSort(node, adj, s, vis);
            }
        }
        s.push(start);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[N];
        
        //convert matrix into adjacency list
        for(int i=0; i<M; i++){
            int start=edges[i][0];
            int dest=edges[i][1];
            int wt=edges[i][2];
            adj[start].push_back({dest, wt});
        }
        
        //do topo sort
       int vis[N]={0};
        stack<int> s;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoSort(i, adj, s, vis);
            }
            
        }
        
        //relaxation of edges
        vector<int> dis(N);
        for(int i=0; i<N; i++){
            dis[0]=INT_MAX;
        }
        dis[0]=0;
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            
            for(auto it: adj[temp]){
                int node=it.first;
                int wt=it.second;
                if(dis[temp]+wt<dis[node]){
                    dis[node]=dis[temp]+wt;
                }
            }
        }
        return dis;
    }
};

//TC: O(N+M) + O(N+M) ~ O(N+M)   ..where O(N+M) indicates dfs traversal and O(N+M) indecates relaxation of edges along with it's adjacent node
//SC: O(N)
