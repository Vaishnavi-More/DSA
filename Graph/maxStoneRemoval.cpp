//GFG: Maximum Stone Removal
//LINK: https://bit.ly/3QHZuE6

class DisjointSet{
    public:
    vector<int> parent, size;
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
        if(p_u==p_v) return;
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // calculate no of rows
        int max_r=0;
        // calculate no of cols
        int max_c=0;
      //O(N)
        for(auto it: stones){
            max_r=max(max_r, it[0]);
            max_c=max(max_c, it[1]);
        }
        
        //object
        DisjointSet obj(max_r+max_c+1);
        
        //traverse stones
      //O(N*4alpha)
        for(auto it: stones){
            int row=it[0];
            int col=it[1]+max_r+1;
            
            //connect row and col
            obj.unionBySize(row, col);
        }
        
        //no of province in a graph
        int components=0;
        
        //if ulimate parent of node is node itself and it's size is greater than 1 this indicate a components
        //if size is 1 this indicate no stones are present in a  particular row or col
        //O(N*4alpha)
        for(int i=0; i<max_r+max_c+1; i++){
           if(obj.parent[i]==i && obj.size[i]>1) components++;
       }
       
       //maximum stones that can be removed 
        return n-components;
        
    }
};

//TC: O(N)
//SC: O(2* (max row index + max column index)) for the parent and size array inside the Disjoint Set data structure.
