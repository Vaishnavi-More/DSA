//GFG: Number of Islands – II – Online Queries
//LINK: https://bit.ly/3w9REfj


/*As in this problem we have to return count of no of islands after every query and graph is changing continuously
so, we will use disjoint set*/

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        //object
        DisjointSet obj(n*m);
        //to store no of island after every query
        vector<int> ans;
        //vis array
        int vis[n][m];
        //sets 2D matrix value to zero
        memset(vis, 0, sizeof vis);
        //no of island
        int cnt=0;
        
        //traverse 
        for(auto it: operators){
            int row=it[0];
            int col=it[1];
            
            //if already visited then push ans and skip the iteration
            if(vis[row][col]){
                ans.push_back(cnt);
                continue;
            }
            
            //else mark as visited and increment count
            vis[row][col]=1;
            cnt++;
            
            //to traverse up, down, left, right
            int drow[]={-1, 0, +1, 0};
            int dcol[]={0, -1, 0, +1};
            
            //traverse
            for(int i=0; i<4; i++){
                
                //current row and col
                int cRow=row+drow[i];
                int cCol=col+dcol[i];
                
                //if it lie within a boundary and it is equal to 1 
                if(cRow>=0 && cRow<n && cCol>=0 && cCol<m && vis[cRow][cCol]==1){
                    //to find no of node and adjnode to make connection in disjoint set if not established
                    int node=row*m+col;
                    int adjNode=cRow*m+cCol;
                    //already not connected
                    if(obj.getUPar(node)!=obj.getUPar(adjNode)){
                        cnt--;
                        obj.unionBySize(node, adjNode);
                    }
                }
            }
            //push current query count
            ans.push_back(cnt);
        }
        
        //final ans
        return ans;
    }
};

/* Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.

Space Complexity: O(Q) + O(N*M) + O(N*M) where Q is no of queries and last two term indicates parent array and size array
*/
