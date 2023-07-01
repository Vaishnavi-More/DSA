//GFG: Floyd Warshall
//LINK:  https://bit.ly/3JZlk4a

/* Floyd warshall algo is multisource algorithm. In this algo we just deal with matrix and below operation is done-
matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j])   ...here k indicates via node
*/

/*How to detect if negative cycle is present in graph?

If the value of particular node is negative than this indicate negative cycle is present.
for(int i=0; i<n; i++){
if(cost[i][i]<0){
}}
*/

void shortest_distance(vector<vector<int>>&matrix){
	    //Slight changes in matrix
	    int n=matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	        }
	    }
	    
	    //Floyd Warshall Algo
	    for(int k=0;k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j]=min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }

      //to detect negative cycle in graph
      for(int i=0; i<n; i++){
       if(matrix[i][j]<0) {
           cout<<" Negative cycle is present";
        }
      }
	    
	    //Undo the changes made at the start
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}

//TC: O(N^3)
//SC: O(N^2)
