//Leetcode: 2658. Maximum Number of Fish in a Grid
//Linke: https://leetcode.com/contest/biweekly-contest-103/problems/maximum-number-of-fish-in-a-grid

private:
    void dfs(int i, int j, int n, int m,vector<vector<int>>& grid, vector<vector<bool>>& vis, int &sum ){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]) return;
        
        //add node value into sum indicating fish present at particular node
        sum+=grid[i][j];
        
        //mark node as visited
        vis[i][j]=1;
        
        //up
        dfs(i-1, j, n, m, grid, vis, sum);
        
        //down
        dfs(i+1, j, n, m, grid, vis, sum);
        
        //left
        dfs(i, j-1, n, m, grid,vis, sum);
        
        //right
        dfs(i, j+1, n, m, grid, vis, sum);
        
        
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        //no of rows
        int n=grid.size();
        
        //no of columns
        int m=grid[0].size();
        
        //create visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        //ans variable used to store maximum number of fish in a grid
        int ans=0;
        
        //traverse grid to find start node
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                //start node is water and not visited one
                if(grid[i][j]!=0 && !vis[i][j]){
                    //for every new start node initialize sum equal to zero indicating no of fishes in a particular water area
                    int sum=0;
                    
                    //call dfs function to traverse all adjacent nodes of start
                    dfs(i, j, n, m, grid, vis, sum);
                    
                    //compare ans with sum and update it with maximum value
                    ans=max(ans, sum);
                    
                }
            }
        }
        
        //return ans
        return ans;
        
    }

//Time Complexity: O(N^2)  ..where N^2 is approximate time required for grid traversal along with dfs call
//SPace Complexity: O(N^2)  ..where N^2 space required for vis array
