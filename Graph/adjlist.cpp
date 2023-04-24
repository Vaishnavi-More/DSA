//Creation of undirected graph using Adjacency Lists
#include<iostream>;
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a[n+1];

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        a[u].push_back(v);
        a[v].push_back(u);
    }
    return 0;
}

//Time Complexity: O(N) where N is no of nodes
//Space Complexity: O(2*E) where E is no of edges   
