//GFG: Eventual Safe States
//Link: https://bit.ly/3C90n59

/*Intuition:
Here all the elements that belong to cycle and which lead to cycle are not safe states
Bcz if cycle is present than it will continue traversing within the loop and it will never reach terminal states.
*/

private:
  bool help(int s,vector<int> adj[], int vis[], int  pathvis[], int chk[] ){
      //mark node as visited
      vis[s]=1;
      pathvis[s]=1;
      
      //traverse it's neighbour nodes
      for(auto it: adj[s]){
          //if neighbour node not visited
          if(!vis[it]){
              if(help(it, adj, vis, pathvis, chk)==true) return true;
          }
          
          //if visited and path followed is same then cycle is present
          else if(pathvis[it]==1) return true;
      }
      
      //backtrack
      chk[s]=1;
      pathvis[s]=0;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        int chk[V]={0};
        vector<int> ans;
        
        //traverse graph
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                help(i, adj, vis, pathvis, chk);
            }
        }
        
        //nodes which are checked are safe states
        for(int i=0; i<V; i++){
            if(chk[i]==1){
                ans.emplace_back(i);
            }
        }
        return ans;
    }

//Leetcode: 802. Find Eventual Safe States
//Link: https://leetcode.com/problems/find-eventual-safe-states

bool dfs(int s, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis, vector<int>& chk){
        vis[s]=1;
        pathvis[s]=1;

        for(auto it: graph[s]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathvis, chk)) return true;
            }
            else if(pathvis[it]==1) return true;
        }

        //backtrack
        chk[s]=1;
        pathvis[s]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> chk(V, 0);
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathvis, chk);
            }
        }
        for(int i=0; i<V; i++){
            if(chk[i]==1){
                ans.emplace_back(i);
            }
        }
        return ans;
        
    }


//Using Topological sort (Kahn's algo)
/*
The nodes which can be topological sorted are safe states since they are not involved in cycle and doesn't lead to cycle
Just we will reverse the edges to apply topo sort.
*/

 vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // reverse the edges i.e u->v to v->u
        vector<int> adjR[V];
         int indg[V]={0};
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                adjR[it].push_back(i);
                indg[i]++;
            }
        }
        
        //Kahn's algorithm 
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indg[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it: adjR[temp]){
                indg[it]--;
                if(indg[it]==0){
                    q.push(it);
                }
            }
        }
        
        //the nodes present in ans vector are safe states 
        sort(ans.begin(), ans.end());
        return ans;
    }

//TC: O(N) +O(N) +O(N+E) ~ O(N+E)
//SC: O(N)
