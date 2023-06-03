//Leetcode: 1302. Deepest Leaves Sum
//Link: https://leetcode.com/problems/deepest-leaves-sum

 int deepestLeavesSum(TreeNode* root) {
        //to store sum of deepest leaves
        int ans;

        //queue for BFS traversal
        queue<TreeNode*> q;

        //insert root
        q.push(root);

        //traverse until queue does not become empty
        while(!q.empty()){
            ans=0;
            int n=q.size();

            //traverse each level
            for(int i=0; i<n; i++){
                TreeNode* temp=q.front();
                q.pop();
                ans+=temp->val;

                //left child
                if(temp->left){
                    q.push(temp->left);
                }

                //right child
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }

        //return
        return ans;     
    }

//TC: O(N)
//SC:O(N)
