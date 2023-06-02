//GFG: Topological sort
//Link:  https://bit.ly/3PvBfsm

/*Intution: 
->We will apply dfs traversal
->once call is completed for a particular node store it into stack
->After complete traversal pop stack element and store it into vector
->Element will be arranged in Topological sort
*/

private:
    void dfs(int start,vector<int> adj[], int vis[], stack<int> &s){
        //DFS traversal
        //mark node as visted
        vis[start]=1;
        
        //traverse it's neighbours node
        for(auto it: adj[start]){
            if(!vis[it]){
                dfs(it, adj, vis, s);
            }
        }
        
        //push element into stack
        s.push(start);
        return ;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //create visited array
	    int vis[V]={0};
	    
	    //stack
	    stack<int> s;
	    
	    //ans vector to store sort
	    vector<int>ans;
	    
	    //traverse graph
	    for(int i=0;i<V; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, s);
	        }
	    }
	    
	    //traverse stack
	    while(!s.empty()){
	        ans.emplace_back(s.top());
	        s.pop();
	    }
	    return ans;
	}

//TC: O(N+E)
//SC: O(N)
