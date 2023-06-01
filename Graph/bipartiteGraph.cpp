//Leetcode: 785. Is Graph Bipartite?
//Link: https://leetcode.com/problems/is-graph-bipartite

//BFS Traversal
bool helper(int start, vector<vector<int>>& graph, vector<int> &vis){
        //BFS traversal

        //create queue
        queue<int> q;

        //push the starting node
        q.push(start);

        //mark it with any one color. -1: uncolored , 0: 1st color  , 1: 2nd color 
        vis[start]=0;

        //traverse
        while(!q.empty()){
            int temp=q.front();
            q.pop();

            //Traverse it's neighbours
            for(auto it: graph[temp]){

                //if neighbour node is not visited
                if(vis[it]==-1){
                    q.push(it);
                    //colour it with opposite colour to current node
                    vis[it]=!vis[temp];
                }

                //if neihbour node is already visited and it's colour is similar to current node indicate it is not a bipartite graph
                else if(vis[it]==vis[temp]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, -1);

        //traverse graph 
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!helper(i,graph, vis)) return false;
            }
        }  
        return true;    
    }

//GFG: Bipartite Graph
//Link: https://practice.geeksforgeeks.org/problems/bipartite-graph

private: 
    bool helper(int start, vector<int> adj[], int vis[]) {
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            // traverse its neighbors
            for (auto it : adj[temp]) {
                if (vis[it] == -1) {
                    vis[it] = !vis[temp];
                    q.push(it);
                } else if (vis[it] == vis[temp]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        int vis[V];
        for (int i = 0; i < V; i++)
            vis[i] = -1;
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                if (!helper(i, adj, vis))
                    return false;
            }
        }
        return true;
    }


//DFS Traversal
private: 
    //DFS traversal
    bool helper(int start, int color, vector<int> adj[], int vis[]) {
        //color the node
        vis[start]=color;
        
        //traverse it's neighbour nodes
        for(auto it: adj[start]){
            
            //if neighbour node is not visited
            if(vis[it]==-1){
              //recursive call
              if((helper(it, !color, adj, vis))==0) return false;
            }
            
            //if neighbour node is already visited then check if it's color is similar to current node
            else if(vis[it]==color) return false;
        }
        
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[]) {
        //visted array
        int vis[V];
        
        //-1: indicates no color, 0: 1st color, 1: 2nd color
        for (int i = 0; i < V; i++){
            vis[i] = -1;
        }
            
        //traverse graph    
        for (int i = 0; i < V; i++) {
            
            //if node not visted
            if (vis[i] == -1) {
                if (!helper(i,0, adj, vis))
                    return false;
            }
        }
        return true;
    }

//Time Complexity: O(N*M)
//Space Complexity: O(N)
