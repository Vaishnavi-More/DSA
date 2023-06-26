//GFG: Implementing Dijkstra Algorithm
//LINK:  https://bit.ly/3KeZZ7j

//Dijkstra using Priority queue

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //priority queue
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //start node push into queue
         pq.push({0,S});
         //create distance vector
         vector<int> dis(V,1e9);
         
         //traverse
         while(!pq.empty()){
             
             //weight of node
             int wt=pq.top().first;
             //node 
             int node=pq.top().second;
             pq.pop();
             
             //traverse it's neighbour
             for(auto it: adj[node]){
                 
                 //distance from node to adjacet node
                 int dist=it[0];
                 //adjacent node
                 int adjNode=it[1];
                 //calculate weight of adjacent node
                 if(dist+wt<dis[adjNode]){
                     dis[adjNode]=dist+wt;
                     //push into queue
                     pq.push({dis[adjNode], adjNode});
                 }
             }
         }
         return dis;
    }

//Dijkstra using set

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dis(V, 1e9);
        dis[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            //returns value store at top of set
            auto it=*(st.begin());
            int node=it.second;
            int  wt=it.first;
            st.erase(it);
            
            //traverse it's adjacent node
            for(auto it: adj[node]){
                int adjNode=it[0];
                int dist=it[1];
                if(wt+dist<dis[adjNode]){
                //if adjacent node is already visited than erase it earlier and then insert the better option
                if(dis[adjNode]!=1e9){
                    st.erase({dis[adjNode], adjNode});
                }
                
                dis[adjNode]=wt+dist;
                st.insert({dis[adjNode], adjNode});
                }
            }
        }
        
      return dis;  
    }

//TC: O(E logV)
//SC: O(E+V)
