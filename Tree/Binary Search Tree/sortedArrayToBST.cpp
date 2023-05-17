//Leetcode: 108. Convert Sorted Array to Binary Search Tree
//Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

TreeNode* helper(vector<int>& nums, int low, int high, int mid){
        //base case
        if(mid<low || mid>high) return NULL;

        //create node
        TreeNode* root=new TreeNode(nums[mid]);

        //recursive call
        root->left=helper(nums, low, mid-1, (low+mid-1)/2);

        root->right=helper(nums, mid+1, high, (mid+1+high)/2);

        //return
        return root;


    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //size of vector
        int n=nums.size();

        //low value
        int low=0;

        //high value
        int high=n-1;

        //middle element
        int mid=(low+high)/2;

        //call function
        TreeNode* root=helper(nums, low, high, mid);

        //return root
        return root;  
    }

//Time Complexity: O(N)
