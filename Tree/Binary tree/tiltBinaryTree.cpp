//Leetcode: 563. Binary Tree Tilt
//Link: https://leetcode.com/problems/binary-tree-tilt

/*
Intuition:
1) In this problem we will do postorder traversal since initially we will calculate left subtree sum and right subtree sum
2) Calculate absolute difference & stored it into ans
3) While returning calculate sum of subtrees
*/


int helper(TreeNode* root, int &ans){
        //postorder traversal
        //base case
        if(root==NULL) return 0;

        //recursive call
        int ls=helper(root->left, ans);
        int rs=helper(root->right, ans);

        //calculate absolute differnce and add it to final ans
        ans+=abs(ls-rs);

        //Adding sum of left subtree & right subtree with current node val
        return ls+rs+root->val;

    }
    int findTilt(TreeNode* root) {
        //ans variable to store the sum of tilt
        int ans=0;

        //calling helper function
        helper(root, ans);

        //returning final ans
        return ans;       
    }

// Time Complexity: O(N)  ...where N is Number of Nodes
//Space Complexity: O(H)  ...where H is height of tree
