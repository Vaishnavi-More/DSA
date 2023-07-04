//Kruskal's Algorithm
//LINK: https://bit.ly/3eLuYvH

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n+1; i++){
            parent[i]=i;
        }
    }
    
    int getUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=getUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int p_u=getUPar(u);
        int p_v=getUPar(v);
        if(size[p_u]<size[p_v]){
            parent[p_u]=p_v;
            size[p_v]+=size[p_u];
        }
        else{
            parent[p_v]=p_u;
            size[p_u]+=size[p_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        int sum=0;
      //O(V+E)
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node, adjNode}});
            }
        }
        DisjointSet obj(V);
      //O(NlogN)
        sort(edges.begin(), edges.end());

      //O(M*4alpha*2)
        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(obj.getUPar(u)!=obj.getUPar(v)){
                sum+=wt;
                obj.unionBySize(u, v);
            }
        }
        return sum;
        
    }
};

//TC: O(E+V) + O(NlogN) + O(M*4alpha*2)
//SC:O(N) +O(N)+O(E)
