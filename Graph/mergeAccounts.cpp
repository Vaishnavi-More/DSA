//GFG: Accounts Merge
//LINK: https://bit.ly/3sl2Xia

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n+1; i++){
            parent[i]=i;
        }
    }
    
    int getUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=getUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int p_u=getUPar(u);
        int p_v=getUPar(v);
        if(size[p_u]<size[p_v]){
            parent[p_u]=p_v;
            size[p_v]+=size[p_u];
        }
        else{
            parent[p_v]=p_u;
            size[p_u]+=size[p_v];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        sort(accounts.begin(), accounts.end());
        int n=accounts.size();
        DisjointSet obj(n);
        // generate map to store email along with node
        unordered_map<string, int> mergeMail;
        for(int i=0; i<n; i++){
            // as emails in accounts matyrix is stored from second index
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                //Mail is not already present in the unordered map
                if(mergeMail.find(mail)==mergeMail.end()){
                    mergeMail[mail]=i;
                }
                //mail is already present then do not store it whereas connect the particular node to
                //the node where the mail already exist
                else{
                    obj.unionBySize(i,mergeMail[mail]);
                }
            }
        }
        
        //generate vector list to store the mails into it
        vector<string> v[n];
      
            for(auto it: mergeMail){
                string mail=it.first;
                int node=obj.getUPar(it.second);
                v[node].push_back(mail);
            }
            
        //store name along with emails
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
                //if node is merge with some other node
                if(v[i].size()==0) continue;
                //else
                sort(v[i].begin(), v[i].end());
                vector<string>temp;
                //enter name
                temp.push_back(accounts[i][0]);
                
                //traverse vector list storing emails and store it into temp
                for(auto it: v[i]){
                  temp.push_back(it);
                }
                ans.push_back(temp);
        }
       sort(ans.begin(), ans.end());
        return ans;
    }
};

/* TC: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. 
The first term is for visiting all the emails. The second term is for merging the accounts. 
And the third term is for sorting the emails and storing them in the answer array.*/

//SC: O(N) 
