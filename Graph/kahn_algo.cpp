//GFG: Topological sort using BFS [Kahn's Algorithm]
//Link:https://bit.ly/3PvBfsm

/*
Problem: Our aim is to implement topological sort using BFS traversal. Which is eventually known as Kahn's Algorithm

Intution:
Create indegree array
The node having indegree 0 can insert into queue 
*/

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //create indegree array
	    int indg[V]={0};
	    
	    //traverse to calculate indegree
	    for(int i=0; i<V; i++){
	        for(auto it: adj[i]){
	            indg[it]++;
	        }
	    }
	    
	    //create queue for BFS traversal 
	    queue<int> q;
	    
	    //Push node having indegree 0
	    for(int i=0; i<V; i++){
	        if(indg[i]==0){
	            q.push(i);
	        }
	    }
	    
	    //create vector to store sorting 
	    vector<int> topo;
	    
	    //traverse until queue becomes empty
	    while(!q.empty()){
	        
	        //store node into vector
	        int temp=q.front();
	        q.pop();
	        topo.emplace_back(temp);
	        
	        //traverse it's neighbour node and decrement neighbour node's indegree
	        for(auto it: adj[temp]){
	            indg[it]--;
	            
	            //if indegree of neighbour node become 0 than it is ready to insert into queue
	            if(indg[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    //return vector
	    return topo;
	}

//TC: O(V+E)
//SC:O(N)
