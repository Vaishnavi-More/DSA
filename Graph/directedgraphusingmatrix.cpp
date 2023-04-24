//Creation of directed graph using adjacency matrix
#include<iostream>
using namespace std;
int main(){
    //n-no of nodes
    //m-no of edges
    int n, m;
    cin>>n>>m;

    //create matrix
    int a[n+1][n+1];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        //store 1
        a[u][v]=1;
      //Ignore below line of code
       // a[v][u]=1;
    }
    return 0;

}

//Time Complexity: O(n) where n is no of nodes
//Space Complexity: O(n^2)     ...Since n+1 * n+1 matrix is created
