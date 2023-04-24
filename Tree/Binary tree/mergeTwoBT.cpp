// Leetcode problem: 617.Merge Two Binary tree

//Link: https://leetcode.com/problems/merge-two-binary-trees

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //If both the roots are NULL then return NULL
        if(root1==NULL && root2==NULL) return NULL;
  
        //If anyone of them is Null then return adjacent one
        else if(root1==NULL && root2!=NULL) return root2;
        else if(root1!=NULL && root2==NULL) return root1;
        
        //Sum up values of both root into root1
        root1->val+=root2->val;
   
        //Recursive calls
        root1->left=mergeTrees(root1->left, root2->left);
        root1->right=mergeTrees(root1->right, root2->right);
  
        //Return root1
        return root1;
        
    }

//Time Complexity: O(n) where n is no of nodes
//Space Complexity: O(n) ...auxillary space acquired by stack & we are not creating new tree but we are making change in the same tree 
