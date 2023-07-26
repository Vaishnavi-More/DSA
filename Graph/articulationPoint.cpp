//GFG: Articulation Point - I
//LINK: https://bit.ly/3w9lfp1

class Solution {
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tim[], int low[], vector<int>& mark){
        vis[node]=1;
        tim[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it, node, adj, vis, tim, low, mark);
                low[node]=min(low[node], low[it]);
                if(tim[node]<=low[it] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else {
                low[node]=min(low[node], tim[it]);
            }
            
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n, 0);
        int tim[n];
        int low[n];
        vector<int> mark(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, tim, low, mark);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
        
        
    }
};

//TC: O(V+2E)
//SC: O(3V)
