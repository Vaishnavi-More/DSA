//Leetcode: 814. Binary Tree Pruning
//Link: https://leetcode.com/problems/binary-tree-pruning

/* Pruning means to delete a particular node 
In this problem we are asked to delete a node who's value is equal to 0 
Remember we can't delete node who's value is zero but it contain child as we will miss the subtree.
So, always check that particular node is leaf node and it's value is equal to zero.
*/

TreeNode* pruneTree(TreeNode* root) {
        //base case
        if(root==NULL) return NULL;

        //recursive call
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);

        //if root val is equal to zero and if it does not conatin any child then we can delete it
        if(root->val==0 && root->left==NULL && root->right==NULL) return NULL;

        //else return root
        return root;
        
    }

//TC: O(N)
//SC: O(H)  ..Auxillary space aquired by stack
