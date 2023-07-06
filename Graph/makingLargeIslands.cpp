//Leetcode: 827. Making A Large Island
//LINK: https://leetcode.com/problems/making-a-large-island

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
    int largestIsland(vector<vector<int>>& grid) {
        //no of rows
        int n=grid.size();
        DisjointSet obj(n*n);

        //to form disjoint set
       //O(N^2)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    continue;
                }
                int drow[]={-1, 0, +1, 0};
                int dcol[]={0, -1, 0,+1};
                //traverse up, down, left, right
                for(int k=0; k<4; k++){
                    int cRow=i+drow[k];
                    int cCol=j+dcol[k];
                    //base condition 
                    if(cRow>=0 && cRow<n && cCol>=0 && cCol<n && grid[cRow][cCol]==1){
                        int node=i*n+j;
                        int adjNode=cRow*n+cCol;
                          obj.unionBySize(node, adjNode);
                    }
                }
                
            }
        }
        
        int ans=0;

        //make changes in graph where 0 is present and check size of island
        //O(N^2)
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                
                //if grid[i][j] is zero
                int drow[]={-1, 0, +1, 0};
                int dcol[]={0, -1, 0,+1};
                set <int> components;

                //traverse up, down, left, right
                for(int k=0; k<4; k++){
                    int cRow=i+drow[k];
                    int cCol=j+dcol[k];

                    //if island is present to it's adjacent
                    if(cRow>=0 && cRow<n && cCol>=0 && cCol<n && grid[cRow][cCol]==1){
                        int node=i*n+j;
                        int adjNode=cRow*n+cCol;
                        int u_p=obj.getUPar(adjNode);
                        components.insert(u_p);
                    }
                }
                int sum=0;
                for(auto it: components){
                    sum+=obj.size[it];
                }
               ans=max(ans, sum+1);
            }
            
        }
        
        //edge case: if entire matrix is stored with one then
        for(int i=0; i<n*n; i++){
            ans=max(ans, obj.size[obj.getUPar(i)]);
        }
        return ans;
    }
};

//TC: O(N^2) + O(N^2) ~ O(N^2)
//SC: O(2*N^2)  for parent and size vector
