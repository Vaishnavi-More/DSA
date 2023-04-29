//Leetcode: 200. Number of Islands
//Link: https://leetcode.com/problems/number-of-islands

private:
  void dfs(int i, int j, int n, int m,vector<vector<char>>& grid, vector<vector<bool>>& vis ){
      //dfs function used for traversal 
      //base case
      if(i<0 || j<0 || i>=n || j>=m|| grid[i][j]!='1' || vis[i][j]) return;
      
      vis[i][j]=1;
      //up
      dfs(i-1, j, n, m, grid, vis);
      
      //down
      dfs(i+1, j, n, m, grid, vis);
      
      //right
      dfs(i, j+1, n, m, grid, vis);
      
      //left
      dfs(i, j-1, n, m, grid, vis);
      
      
      
  }
public:
    int numIslands(vector<vector<char>>& grid) {
        //no of rows
        int n=grid.size();

        //no of column
        int m=grid[0].size();

        //create visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        //count no of islands present
        int cnt=0;

        //traverse grid to find start position of land
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //start position found 
                    cnt++;
                    //call dfs for traversing adjacent nodes present to start node
                    dfs(i,j,n,m,grid, vis);
                }
            }
        }
        
        //return number of islands present
        return cnt;
        
    }

//GFG Link: https://bit.ly/3oT9Ndg
//Slight change in problem here we have to traverse in all possible direction whereas in above problem we were allowed to traverse in only four possible directions.

private:
  void dfs(int i, int j, int n, int m,vector<vector<char>>& grid, vector<vector<bool>>& vis ){
      //dfs function used for traversal 
      //base case
      if(i<0 || j<0 || i>=n || j>=m|| grid[i][j]!='1' || vis[i][j]) return;
      
      vis[i][j]=1;
      //up
      dfs(i-1, j, n, m, grid, vis);
      
      //down
      dfs(i+1, j, n, m, grid, vis);
      
      //right
      dfs(i, j+1, n, m, grid, vis);
      
      //left
      dfs(i, j-1, n, m, grid, vis);
      
      //top right corner
      dfs(i-1, j+1, n, m, grid, vis);
    
      //top left corner
      dfs(i-1, j-1, n, m, grid, vis);
    
      //bottom left corner
      dfs(i+1, j-1, n, m, grid, vis);
    
      //bottom right corner
      dfs(i+1, j+1, n, m, grid, vis);
      
      
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        //no of rows
        int n=grid.size();

        //no of column
        int m=grid[0].size();

        //create visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        //count no of islands present
        int cnt=0;

        //traverse grid to find start position of land
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    //start position found 
                    cnt++;
                    //call dfs for traversing adjacent nodes present to start node
                    dfs(i,j,n,m,grid, vis);
                }
            }
        }
        
        //return number of islands present
        return cnt;
    }

//Time Complexity: O(9*N^2) ~ O(N^2)  ..where N^2 is traversing grid and 9 is approximate number of time dfs function calle to visit neighbors
//Space complexity: O(N^2)  ..where N^2 space is required to store visited array
