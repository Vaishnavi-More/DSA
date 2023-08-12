//CodeStudio: Maximum sum of non-adjacent elements
//LINK: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

//Recursive approach
#include <bits/stdc++.h> 
int help(int i, vector<int> &nums){
    //if we are at 0th index pick the element
    if(i==0) return nums[0];

    //if we reach negative index then simply return
    if(i<0) return 0;

    //pick the current element then you have to jump 2 steps below since
    //you can choose adjacent element
    int pick=nums[i]+help(i-2, nums);

    //if not pick then jump 1 step below
    int notPick=0+help(i-1, nums);

    //consider best out of pick and not pick
    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return help(n-1, nums);
}

//TC:O(2^n)
//SC: O(n)

//Memoization (top down approach) 

#include <bits/stdc++.h> 
int help(int i, vector<int> &nums, vector<int> &dp){
    //if we are at 0th index pick the element
    if(i==0) return nums[0];

    //if we reach negative index then simply return
    if(i<0) return 0;

    //if already computed
    if(dp[i]!=0) return dp[i];

    //pick the current element then you have to jump 2 steps below since
    //you can choose adjacent element
    int pick=nums[i]+help(i-2, nums, dp);

    //if not pick then jump 1 step below
    int notPick=0+help(i-1, nums, dp);

    //consider best out of pick and not pick
    dp[i]= max(pick, notPick);
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n, 0);
    dp[0]=nums[0];
     help(n-1, nums, dp);
     return dp[n-1];
}

//TC:O(n)
//SC: O(n) + O(n)  ..stack and dp array

//Tabulation

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n, 0);
    //base case
    dp[0]=nums[0];

    //traverse
     for(int i=1; i<n; i++){
         //pick
         int pick=nums[i];
         if(i==1){
             pick=pick+0;
         }
         else if(i>1) pick+=dp[i-2];

         //not pick
         int notPick=0+dp[i-1];

         //choose best 
         dp[i]=max(pick, notPick);
     }
     return dp[n-1];
}

//TC:O(n)
//SC: O(n) .. dp array

//Space Optimization:
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int p1=nums[0], p2=0;

    //traverse
     for(int i=1; i<n; i++){
         //pick
         int pick=nums[i];
         if(i==1){
             pick+=0;
         }
         else if(i>1){
             pick+=p2;
         }

         //not pick
         int notPick=0+p1;
         int curr=max(pick, notPick);
         p2=p1;
         p1=curr;
         
     }
     return p1;
}

//TC:O(n)
//SC: O(1) 
