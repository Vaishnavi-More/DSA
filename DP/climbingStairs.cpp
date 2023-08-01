//Leetcode: 70. Climbing Stairs
//LINK: https://leetcode.com/problems/climbing-stairs

//memoization (Top to bottom Approach)
int help(int n, vector<int>& dp){
        //Base case
        //Two ways to reach 2nd step and 1 way to reach 1st step
        if(n<=2) return n;

        //if already calculated
        if(dp[n]!=-1) return dp[n];

        //else 
        dp[n]=help(n-1, dp) +help(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        //memoization 
        vector<int>dp(n+1, -1);
        return help(n, dp);
}

//TC: O(n);
//SC: O(n)+ O(n) ...one for stack and one for dp vector

//Tabulation
int climbStairs(int n) {
        //tabulation
        //edge case
        if(n<=2) return n;

        //dp vector
        vector<int>dp(n+1, -1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        //traverse from 3 uptil nth steps
        for(int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];        
}

//TC: O(n);
//SC: O(n) ..for dp vector


