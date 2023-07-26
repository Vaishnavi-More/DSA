//Leetcode: 1192. Critical Connections in a Network
//Bridges in Graph – Using Tarjan’s Algorithm of time in and low time
//LINK: https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, int tim[], int low[], vector<vector<int>> &bridges ){
        //mark node as vistied
        vis[node]=1;

        //add steps and low of node
        tim[node]=low[node]=timer;

        //increment timer
        timer++;

        //traverse adjacent node
        for(auto it: adj[node]){

            //if adjacent node is parent then skip
            if(it==parent) continue;

            //if adjacent node is not visited
            if(vis[it]==0){

                //call dfs 
                dfs(it, node, adj, vis, tim, low, bridges);

                //compare low of node along with it's adjacent and update to minimum value
                low[node]=min(low[node], low[it]);

                //if lowest reasching time of adjacent node is less than steps required to reach node  
                //than it indicate bridge is present
                if(tim[node]<low[it]){
                    bridges.push_back({it, node});
                }
            }

            //if adjacent node is already visited
            else{
                low[node]=min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //store graph into adjacency list
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //indicate steps required to reach node
        int tim[n];

        //lowest reaching time
        int low[n];

        //to store bridges present in a graph
        vector<vector<int>> bridges;

        //visited array
        vector<int>vis(n, 0);

        //dfs call
        dfs(0, -1, adj, vis, tim, low, bridges);
        return bridges;

        
        
    }
};

//TC: O(V+2E)
//SC:O(V+2E)
