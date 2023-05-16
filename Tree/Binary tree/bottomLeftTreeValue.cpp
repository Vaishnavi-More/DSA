//Leetcode: 513. Find Bottom Left Tree Value
//Link:https://leetcode.com/problems/find-bottom-left-tree-value

/*Intution: We can get leftmost element at each level through BFS trvaresal and we will keep on updating leftmost elemet at each level.
At the end we will found the leftmost element of last level */

int findBottomLeftValue(TreeNode* root) {
        //store leftmost node
        TreeNode* leftmost=root;

        //create queue
        queue<TreeNode*> q;

        //insert root
        q.push(root);

        //BFS traversal
        while(!q.empty()){
            
            //no of nodes in queue
            int n=q.size();

            //frontmost element in queue is the leftmost element of each level
            leftmost=q.front();

            //traverse 
            for(int i=0; i<n; i++){

                //pop front element 
                TreeNode* temp=q.front();
                q.pop();

                //if left child exist
                if(temp->left){
                    q.push(temp->left);
                }

                //if right child exist
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }

        //return leftmost element of last level
        return leftmost->val;
        
    }

//TC: O(N)
//SC: O(N)
