//GFG: Shortest Distance in a Binary Maze
//LINK: https://bit.ly/3QLxjET

/*Here we will apply Dijkstra using queue.
Why not priority queue?
Bcz as all the edges are unit weighted so queue will store everything in increasing order.
We require queue when edges are weighted diferently.
Thus we reduce complexity by logn*/

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        
        //edge case
        if(source.first==destination.first && source.second==destination.second) return 0;
        // distance vector
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        
        //dis of src node is always zero
        dis[source.first][source.second];
        
        //queue 
        queue<pair<int,pair<int, int>>> q;
        q.push({0,{source.first, source.second}});
        
        //deltarow and delta col to traverse up down left right
        int drow[4]={-1, 0, +1, 0};
        int dcol[4]={0, -1, 0, +1};
        
        //traverse
        while(!q.empty()){
            // store queue topmost element
            auto it=q.front();
            int wt=it.first;
            int row=it.second.first;
            int col=it.second.second;
            //pop element
            q.pop();
            
            //traverse it's neighbour
            for(int k=0; k<4; k++){
                //traverse up dowm left right
                int currRow=row+drow[k];
                int currCol=col+dcol[k];
                
                //condition
                if(currRow>=0 && currRow<n && currCol>=0 && currCol<m && wt+1<dis[currRow][currCol] && grid[currRow][currCol]==1){
                    dis[currRow][currCol]=wt+1;
                    
                    //chk if you reach destination
                    if(currRow==destination.first && currCol==destination.second) return wt+1;
                    //push into queue
                    q.push({wt+1, {currRow, currCol}});
                }
            }
            
            
        }
        //if you can't reach destination then return -1
        return -1;
    }

//TC: O(4*N*M)
//SC: O(N*M)
