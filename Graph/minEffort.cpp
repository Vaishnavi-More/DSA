//GFG: Path With Minimum Effort
//LINK: https://bit.ly/3dMBvq6

int MinimumEffort(vector<vector<int>>& heights) {
        // no of rows
        int n=heights.size();
        //no of cols
        int m=heights[0].size();
        
        //vector to store effort
        vector<vector<int>> effort(n, vector<int>(m,1e9));
        
        //effort of source node
        effort[0][0]=0;
        
        //create priority queue to store {effort,{row,col}}
        priority_queue<pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>>pq;
        
        //push source node into queue
        pq.push({0,{0,0}});
        
        //to traverse up, down, top, bottom
        int drow[4]={-1, 0,+1,0};
        int dcol[4]={0, -1, 0, +1};
        
        //Until queue becomes empty
        while(!pq.empty()){
            
            //topmost element
            auto it=pq.top();
            pq.pop();
            
            //node effort
            int e=it.first;
            
            //node position in grid
            int row=it.second.first;
            int col=it.second.second;
            
            //if we reach destination 
            if(row==n-1 && col==m-1) return e;
            
            //traverse it's neighbour node
            for(int k=0; k<4; k++){
                int cRow=row+drow[k];
                int cCol=col+dcol[k];
                
                //base condition
                if(cRow>=0 && cRow<n && cCol>=0 && cCol<m){
                    
                    //effort between current position from earlier one if neweffort 
                 // calculated is smaller than earlier effort then consider earlier one
                 //Since effort is maximum difference in a path
                    int diff=max(abs(heights[row][col]-heights[cRow][cCol]), e);
                    
                    if(diff<effort[cRow][cCol]){
                            effort[cRow][cCol]=diff;
                            pq.push({diff,{cRow, cCol}});   
                    }
                }
            }
            
        }
        //if unreachable
        return 0;
    }

//TC of Dijkstra Algo is O(E logV) here E is no of edges, in case of grid it is n*m*4 and V is no of nodes i.e n*m

//TC: O(N*M*4 log(N*M))
//SC:O(N*M)
