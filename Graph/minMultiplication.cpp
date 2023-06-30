//GFG: Minimum Multiplications to Reach End
//LINK: https://bit.ly/3AugzNb

/*You are given start no and end no
Your target is to reach end no within minimum steps.
You can generate new no by multiplying start with the elements in array and consider the new no as start node
In this fashion you keep on continuing until u reach end within minimum no of steps*/

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // create distance vector of size 10^5 since it's the constraints 
        vector<int>dis(100000,INT_MAX);
        
        //queue {step, node}
        queue<pair<int, int>> q;
        
        //start node distance is always zero
        dis[start]=0;
        
        q.push({0,start});
        
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int step=it.first;
            int node=it.second;
            
            //travere array
            for(int i=0; i<arr.size(); i++){
                
                //multiply node with array element 
                int adjNode=(node*arr[i]) % 100000;
                
                //the steps required to reach new node is greater than current step+1 thjan 
                //update steps of new node to smaller value
                if(step+1<dis[adjNode]){
                    dis[adjNode]=step+1;
                    
                    //if we reach end
                    if(adjNode==end) return step+1;
                    
                    q.push({step+1, adjNode });
                }
            }
        }
        
        //if unreachable
        return -1;
    }

//TC= 100000 * n   since atmax we can generate 10^5 nodes and every time multiply it with array.size no of elements
//SC=O(10000*n)
