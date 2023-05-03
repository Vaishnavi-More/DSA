//Leetcode: 130. Surrounded Regions | Replace O’s with X’s
//Link:https://leetcode.com/problems/surrounded-regions

//Using BFS Traversal

void solve(vector<vector<char>>& board) {
        //BFS traversal
        //no of rows
        int n=board.size();

        //no of cols
        int m=board[0].size();

        //create visited array
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        //{row, col}
        queue<pair<int, int>> q;

        //traverse bounaries
        for(int j=0; j<m; j++){
            //first row
            if(board[0][j]=='O' && !vis[0][j]){
                q.push({0, j});

            }
            
            //last row
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                 q.push({n-1, j});
            }
        }

        for(int i=0; i<n; i++){

            //first col
            if(board[i][0]=='O' &&!vis[i][0]){
                q.push({i, 0});

            }

            //last col
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                 q.push({i, m-1});
            }

        }

        //up, down, right, left
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, -1, 0, +1};

        //bfs traversal
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            vis[row][col]=1;
            q.pop();

            //traverse current cell's neighbours
            for(int k=0; k<4; k++){
                //neighbour row
                int i=row+drow[k];

                //neighbour col
                int j=col+dcol[k];

                //condition check
                if(i>=0 && i<n && j>=0 && j<m && board[i][j]=='O' && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }

        //tarverse grid and check O's position which is unvisited and convert them into X's

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }    
    }

//Time Complexity: O(N*M*4) + O(N) +O(M)
//Space Complexity: O(N*M)+O(N*M) ~ O(N*M)
