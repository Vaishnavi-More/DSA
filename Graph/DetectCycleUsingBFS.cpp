//GFG: Detect cycle in an undirected graph using BFS
//Link:https://bit.ly/3cZMJXp

/* Cycle is present in graph if current node neighbour is already visited by someone else but the neighbour node is not parent node. */

private:
  bool bfs(int src, vector<int> adj[], bool vis[]){
      //create queue
      //{child, parent}
      queue<pair<int, int>> q;
      
      //push starting node into queue
      q.push({src, -1});
      
      //mark it as visited
      vis[src]=1;
      
      //traverse until queue becomes empty
      while(!q.empty()){
          
          //child indicate current node
          int child=q.front().first;
          
          //parent indicate the current node where it come from
          int parent=q.front().second;
          
          //delete front element
          q.pop();
          
          //traverse its neighbour
          for(auto it: adj[child]){
              
              //if current node's neighbour is not visited 
              if(!vis[it]){
                  q.push({it, child});
                  vis[it]=1;
              }
              //child's neighbour node is already visited but that neighbour node is not the parent this indicate cycle is present
              else if(parent!=it){
                  return true;
              }
          }
      }
      
      //cycle not present 
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
                if(bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }

//Time Complexity: O(N) + O(V+2E)  ..where O(N) for traversal of start node and O(V+2E) for bfs traversal
//SPace Complexity: O(N)+O(N)~O(N)  ..to store queue and visited array
