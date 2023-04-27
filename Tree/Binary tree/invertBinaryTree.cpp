//Leetcode: 226. Invert Binary Tree
//Link: https://leetcode.com/problems/invert-binary-tree

/* Intution:
In this problem we need to create the mirror image of tree.
Simply we need to swap left node with right node and this problem can be easily solved with the help of recursion.
We will try to create mirror image for left subtree and right subtree and finally mirror image of entire tree will be created.

Note: We have to swap nodes not value present in it.
*/

TreeNode* invertTree(TreeNode* root) {
      //base case
      if(root==NULL) return NULL;

      //recursive call
      invertTree(root->left);
      invertTree(root->right);

      //swap left subtree & right subtree
      swap(root->left, root->right);
      return root;
        
    }
    
  //Time Complexity: O(N) where N is no of nodes
  //Space Complexity: O(H) where H is height of tree
