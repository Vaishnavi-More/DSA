//Leetcode: 104.Maximum Depth of Binary tree
//Link: https://leetcode.com/problems/maximum-depth-of-binary-tree

int maxDepth(TreeNode* root) {
        //base case
        if(root==NULL) return 0;

        //recursive call
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        
        //Consider maximum depth among left subtree and right subtree and add one into it
        return max(l,r)+1;

    }

//Time Complexity: O(N) where N is no of nodes
//Space Complexity: O(H) where H is height of tree
//Space complexity range from O(logN) to O(N)
