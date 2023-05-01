// Leetcode: 542.Distance of nearest cell having 0 || 0/1 matrix
//Link: https://leetcode.com/problems/01-matrix

/* In this problem you simply have to find minimum distance at which 0 is present from current node
So, simply we will find nearest 0 using BFS technique as it provide minimum distance*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //no of rows
        int n=mat.size();

        //no of cols
        int m=mat[0].size();

        //matrix used to stored distance 
        vector<vector<int>> dis(n, vector<int>(m, 0));

        //create vis matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //create queue
        //{{row, col}, steps}
        queue<pair<pair<int, int>, int>> q;

        //traverse mat[] to find postion of 0's in matrix
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){

                //conatining 0
                if(mat[i][j]==0){

                    //here steps is equal to zero bcz this 0 are at the most minimum distance fron current node
                    q.push({{i,j}, 0});
                    //mark it as visited
                    vis[i][j]=1;
                }
            }
        }


        //create array to indicate up, down, right, left
        int drow[]={-1, 0, +1, 0};
        int dcol[]={0, -1, 0, +1};

        //traverse until queue becomes empty
        while(!q.empty()){

            //current row
            int row=q.front().first.first;

            //current col
            int col=q.front().first.second;

            //no of steps
            int steps=q.front().second;

            //store into dis matrix
            dis[row][col]=steps;

            //delete front
            q.pop();

            //traverse all it's 4 neighbour nodes
            for(int k=0; k<4; k++){

                //move up, down, right, left
                int i=row+drow[k];
                int j=col+dcol[k];

                //check if the node is not visited
                if(i>=0 && i<n && j>=0 && j<m && vis[i][j]!=1){
                    //push it into queue
                    q.push({{i, j}, steps+1});

                    //mark as visited
                    vis[i][j]=1;
                }
            }
        }

        //return distance matrix
        return dis;   
    }

//Time Complexity: O(N*M) + O(4*N*M)  ..for BFS traversal O(N*M) and as we are traversing it's 4 adjacent neighbour therefore O(N*M*4) & O(N*M) for traversal of matrix
//Space Complexity: O(N*M)+O(N*M)+O(N*M)  ..for dis matrix, vis matrix and queue
