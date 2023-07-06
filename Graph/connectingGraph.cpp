//GFG: Connecting the graph
//LINK:  https://bit.ly/3QGtkcd

/*Minimum no of operations performed to make network connected*/

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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        DisjointSet obj(n);
        //count no of extra edges present in a graph
        int extraEdge=0;
        
        //O(E*4alpha)
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            
            //if ultimate parent of both node are same this indicate extra edge is present
            if(obj.getUPar(u)==obj.getUPar(v)){
                extraEdge++;
            }
            
            //else they are not connected so connect them
            else{
                obj.unionBySize(u,v);
            }
        }
        
        //count no of connected components
        //O(N*4alpha)
        int province=0;
        for(int i=0; i<n; i++){
            if(obj.getUPar(i)==i){
                province++;
            }
        }
        
        //no of available extra edges must be more than no of available components-1
        if(extraEdge>=province-1) return province -1;
        
        //if not then 
        return -1;
        
    }
};

//TC: O(E*4alpha) + O(N*4alpha)
//SC: O(2N)   ...for parent and size array
