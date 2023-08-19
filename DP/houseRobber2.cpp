// Leetcode:213.House Robber 2
//LINK: https://leetcode.com/problems/house-robber-ii/

/*Approach:
Similar to maximum sum of non adjacent elements 
Just here we elements are arranged in circular fashion 
So, we can't include first and last element together.

Therefore we will do similar task but on array starting from 0 to n-2 & for an array starting from 1 to n-1
ANd consider maximum out of it.
*/

class Solution {
    private:
     int robHelp(vector<int>& nums) {
        int n=nums.size();
        int p2=nums[0];
        int p1=0;

        //traverse 
        for(int i=1; i<n; i++){
            int pick=nums[i];
            //condition to check if we are at 1th index 
            if(i>1) {
                pick+=p1;
            }

            //not pick
            int notPick=0+p2;

            //calculate maximum out of pick and not pick
            int curr=max(pick, notPick);

            //updation
            p1=p2;
            p2=curr;
        }
        return p2;
        
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        //edge case if array element contain only 1 element 
        if(n==1) return nums[0];
        vector<int> t1, t2;

        //traverse 
        for(int i=0; i<n; i++){
            //not includng last element 
            if(i!=n-1) t1.push_back(nums[i]);

            //including first element
            if(i!=0) t2.push_back(nums[i]);
        }
        
        //function call for vector consisting elements from 0 to n-2
        int a1=robHelp(t1);

        //function call for vector consisting elements from 1 to n-1
        int a2=robHelp(t2);

        //consider maximum 
        return max(a1, a2);

        
    }
};

//TC: O(N)
//SC: O(1)
