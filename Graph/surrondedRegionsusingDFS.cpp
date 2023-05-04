//Leetcode: 130. Surrounded Regions | Replace O’s with X’s
//Link:https://leetcode.com/problems/surrounded-regions

//Using DFS Traversal

void dfs(int i, int j, int n, int m,vector<vector<char>>& board, vector<vector<bool>>& vis ){
        //DFS traversal
        //base case
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='X' || vis[i][j]) return;

        //mark cell as visited
        vis[i][j]=1;

        //traverse up
        dfs(i-1, j, n, m, board, vis);

        //traverse down
        dfs(i+1, j, n, m, board, vis);

        //traverse left
        dfs(i, j-1, n, m, board, vis);

        //traverse right
        dfs(i, j+1, n, m, board, vis);

    }
    void solve(vector<vector<char>>& board) {
        //no of rows
       int n=board.size();

       //no of cols
       int m=board[0].size();

       //visited array
       vector<vector<bool>> vis(n, vector<bool>(m, 0));

       //traverse boundaries
       for(int j=0; j<m; j++){

           //first row
           if(board[0][j]=='O' && !vis[0][j]){
               dfs(0, j, n, m, board, vis);
           }

           //last row
           if(board[n-1][j]=='O' && !vis[n-1][j]){
               dfs(n-1, j, n, m, board, vis);
           }
       }

       for(int i=0; i<n; i++){

           //first col
           if(board[i][0]=='O' && !vis[i][0]){
               dfs(i, 0, n, m, board, vis);
           }

           //last col
           if(board[i][m-1]=='O' && !vis[i][m-1]){
               dfs(i, m-1, n, m, board, vis);
           }
       }

       //traverse board matrix to convert unvisted O's into X
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(board[i][j]=='O' && !vis[i][j]){
                   board[i][j]='X';
                   vis[i][j]=1;
               }
           }
       }
    }

//Time Complexity: O(N*M*4) + O(N) +O(M)
//Space Complexity: O(N*M)+O(N*M) ~ O(N*M)
