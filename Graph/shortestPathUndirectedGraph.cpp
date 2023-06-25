//GFG: Shortest path in Undirected Graph having unit distance
//LINK: https://bit.ly/3RGnHLH

/* Approach: We will do bfs traversal and
while traversing particular node's adjacent node we will relax the edges and push it into queue*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       
       //create adjacency list to convert 2D matrix into adjacency list
       vector<int> adj[N];
       for(auto it:edges){
           //For undirected graph: u->v as well as v->u
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       
        // create distance vector to store shortes distance
       vector<int> dis(N, 1e9);
       
       //distance to src is always zero
       dis[src]=0;
       
       //create queue for BFS traversal
       queue<int> q;
       q.push(src);
       
       //traverse
       while(!q.empty()){
           int temp=q.front();
           q.pop();
           
           //traverse it's adjacent node
           for(auto it: adj[temp]){
               
               //relax it's edges
               if(dis[temp]+1<dis[it]){
                   dis[it]=dis[temp]+1;
                   //push into queue
                   q.push(it);
               }
           }
       }
       
       //to handel edge cases if patrh doesn't lie to from src to particular node then we have to return -1
       vector<int> ans(N,-1);
         for(int i = 0;i<N;i++) {
            if(dis[i] != 1e9) {
                ans[i] = dis[i]; 
            }
        }       

       return ans;
    }
};

//TC: O(N+2M)
//SC: O(N)
