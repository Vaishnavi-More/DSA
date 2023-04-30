//Leetcode: 994. Rotting Oranges
//Link: https://leetcode.com/problems/rotting-oranges

/*Why to use BFS traversal?

See, in this problem we have to return minimum time required to rotten oranges and as at the same time we are rottening the adjacent fresh oranges. 
Intially its neighbour at 1unit of time then it's neighbours neighbour at 2 unit of time and so on. 
SO, simply we can see here intially level 1 element are rotten at 1 unit of time then level 2 at 2 unit of time & this continues.
*/

int orangesRotting(vector<vector<int>>& grid) {

       //no of rows
       int n=grid.size();

       //no of cols
       int m=grid[0].size();

       //create queue as we are doing bfs traversal
       //{{r,c}, t}
       queue<pair<pair<int, int>, int>>q;

       //create visited array
       int vis[n][m];

       //count total no of fresh oranges in a grid
       int cntFresh=0;
        
        //traverse matrix to find position of all rotten oranges
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                //containing rotten orange 
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    //mark them as visited
                    vis[i][j]=2;
                }

                //otherwise mark them as 0
                else{
                    vis[i][j]=0;
                }

                //if fresh orange is present increment the count
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        //ans variable stores the min time required to rott all oranges
        int ans=0;

        //delr & delc are the arrays indiacting direction i.e. up, down, left, right
        int delr[]={-1, 0, +1, 0};
        int delc[]={0, 1, 0, -1};

        //cnt variable count the no of fresh oranges rotten
        int cnt=0; 

        //Traverse until queue becomes empty
        while(!q.empty()){

            //row
            int r=q.front().first.first;

            //col
            int c=q.front().first.second;

            //time
            int time=q.front().second;

            //update ans accordingly 
            ans=max(ans, time);
            q.pop();

            //traverse all 4 neighbours of rotten orange
            for(int i=0; i<4; i++){

                //traverse up, down, left, right
                int nrow=r+delr[i];
                int ncol=c+delc[i];

                //check if grid[nrow][ncol] is fresh orange and is not visited
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid [nrow][ncol]==1 && vis[nrow][ncol]==0 ){

                    //push it into queue
                    q.push({{nrow, ncol}, time+1});

                    //mark fresh oranges as rotten into vis[]
                    vis[nrow][ncol]=2;

                    //increment cnt as fresh orange has rotten
                    cnt++;
                }
            }           
        }

        //if all of the fresh oranges are not rotten then return -1
         if(cntFresh!=cnt) return -1;

         //else return ans
         return ans;
    }

//Time Complexity: O(N*M)+ O(N*M*4)  ..where O(N*M) for tarversal of entire matrix & O(N*M*4) as we are traversing neighbours of every node
//Space Complexity: O(N*M)+O(N*M)  ..O(N*M) for vis array & O(N*M) for queue data structure
