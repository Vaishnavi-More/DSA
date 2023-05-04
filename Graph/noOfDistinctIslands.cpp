//GFG: Number of Distinct Islands
//Link:https://bit.ly/3AsA08W

void dfs(int i, int j, int n, int m, int srow, int scol, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>> & v ){
        //base case
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0 || vis[i][j]) return;
        
        //mark cell as visited
        vis[i][j]=1;
        
        //subtract currrow and currcol with startrow &startcol
        v.push_back({i-srow, j-scol});
        
        //up
        dfs(i-1, j, n, m, srow, scol, grid, vis, v);
        
        //down
        dfs(i+1, j, n, m,srow, scol, grid, vis, v);
        
        //left
        dfs(i, j-1, n, m,srow, scol, grid, vis,v);
        
        //right
        dfs(i, j+1, n, m,srow, scol, grid, vis,v);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // no of rows
        int n=grid.size();
        
        //no of cols
        int m=grid[0].size();
        
        //create visited array 
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        //create set
        set<vector<pair<int, int>>> s;
        
        //traverse grid
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                //if cell conatin 1 then call dfs and the cell is unvisited
                if(grid[i][j]==1 && !vis[i][j]){
                    
                    //create vector to store shape of island
                    vector<pair<int, int>> v;
                    
                    //dfs call
                    dfs(i, j, n, m,i, j, grid, vis, v);
                    
                    //insert the shape into set
                    s.insert(v);
                }
                
            }
        }
        
        //return suize of set as set store all values in distinct fashio so even if duplicates are present it will be cosidered as 1
        return s.size();
        
    }

//Time Complexity: O(N*M)
//Space Complexity: O(N*M)
