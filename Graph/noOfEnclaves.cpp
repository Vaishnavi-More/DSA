//Leetcode: 1020. Number of Enclaves
//Link: https://leetcode.com/problems/number-of-enclaves

/* Intution: The 1 which are present at boundaries and it's neighbour 1 can walk off boundaries.
So, we will mark such 1's as visited and count the rest of 1's and return count*/

 int numEnclaves(vector<vector<int>>& grid) {
        //no of rows
        int n=grid.size();

        //no of cols
        int m=grid[0].size();

        //visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        //create queue {row, col}
        queue<pair<int, int>> q;

        //travrese boundaries
        for(int j=0; j<m; j++){

            //1st row
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0, j});
                vis[0][j]=1;
            }

            //last row
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1, j});
                vis[n-1][j]=1;
            }
        }

        for(int i=0; i<n; i++){

            //1st col
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
            }
            //last col
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        
        //indicates up, down, bottom, top
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, -1, 0, +1};

        //BFS traversal
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            vis[row][col]=1;
            q.pop();

            //traverse neighbours
            for(int k=0; k<4; k++){
                int i=row+drow[k];
                int j=col+dcol[k];

                //adjacent 1's
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1 && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }

        //indicate no of 1's cannto walk off boundary
        int cnt=0;

        //traverse grid and increment count if 1 is not visted 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }

            }
        }

        //return cnt
        return cnt;
        
    }

//Time Complexity: O(N*M*4) + O(N) +O(M)
//Space Complexity: O(N*M)+O(N*M) ~ O(N*M)
