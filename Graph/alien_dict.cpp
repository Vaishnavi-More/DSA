// Leetcode: Alien Dictionary
//Link: https://leetcode.com/problems/alien-dictionary

/* Problem: Our aim is to find the order of allien dictionary.
  Where N - indicates no of strings
        K - indicates no of character present in dictionary
*/

/* Approach:
  1) Compare given string and find why particular string is present before the another one and form edges between them.
  2) As our goal is to find the order so we will use topological sort.
 
  Eg. dict = {"baa","abcd","abca","cab","cad"}
  Here "baa" is placed before "abcd" this indicate b lies before a in alien dictionary order.
  Similarly, "abcd" lie before "abca" this indicate d lie before a.
  Similarly, "abca" lie before "cab" this indicate a lie before c.

  So, we can say the order will be b ->a - > c
                                   \   ^
                                    \  |
                                      > d
  order: bdac

  Note: We will assume a as 0th node, b as 1st node, d as 2nd nd node
  */
  
  
class Solution{
    private:
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
    
public:
	string findOrder(string dict[], int N, int K) {
	    //generate adjavcency list
		vector<int> adj[K];
		
		//compare strings and whenever u find different char at same position than generate a edge i.e u->v
		for(int i=0; i<N-1; i++){
		    string s1=dict[i];
		    string s2=dict[i+1];
		    int len=min(s1.size(), s2.size());
		    
		    //traverse string
		    for(int i=0; i<len; i++){
		        
		        //different char
		        if(s1[i]!=s2[i]){
		            adj[s1[i]-'a'].push_back(s2[i]-'a');
		            
		            //once u find diff move forward to next strings
		            break;
		        }
		    }
		}
		
		//using topological sorting to find the order
		vector<int> topo= topoSort(K, adj);
		
		//convert vector into string
		string s="";
		for(auto it: topo){
		    s=s+char(it+'a');
		}
		return s;
	}
};

//TC: O(V+E)
//SC:O(N)
