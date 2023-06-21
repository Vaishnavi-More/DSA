//Leetcode: 207. Course Schedule
//Link: https://leetcode.com/problems/course-schedule

/* Problem is to arrange courses in u->v format so simply we will check if cycle is present in directed graph or another approach is topological sort
Simply, trace give 2D matrix into u->v format and apply topo sort or using DFS traversal 
  */

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;

      //we will trace prerequisites as u->v form present in graph
        vector<int> adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

      //create indegree array
	    int indg[V];
        for(int i=0; i<V; i++){
            indg[i]=0;
        }
	    
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

        //if all elements are successfully arranged in topological sorting than this indicate we can schedule course 
        if(topo.size()==V) return true;
        return false;
        
    }

//TC: O(V+E)
//SC:O(N)
