//Creation of undirected graph 
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
        a[v][u]=1;
    }
    return 0;

}