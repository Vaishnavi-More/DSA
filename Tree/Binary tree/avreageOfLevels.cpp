//Leetcode Question- 637. Average of Levels in Binary Tree

//Link: https://leetcode.com/problems/average-of-levels-in-binary-tree

vector<double> averageOfLevels(TreeNode* root) {
         vector<double> v;
        if(root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){ 
            int n =q.size(); 
            double avg=0, sum=0;
            for(int i=0; i<n; i++){
            TreeNode* temp=q.front();
            q.pop();
            sum+=temp->val;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
            avg=sum/n;
            v.push_back(avg);

        }
        return v;

        
    }

//Time Complexity: O(N) 
//Space Complexity: O(N)
