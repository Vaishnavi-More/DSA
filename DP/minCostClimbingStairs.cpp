//Leetcode: 746. Min Cost Climbing Stairs
//LINK: https://leetcode.com/problems/min-cost-climbing-stairs

//Recursion:
class Solution {
public:
    int help(int n, vector<int>& cost, int tar){
      //base case 
      //start is either 0 or 1 index
        if(n<=1) return cost[n];

      //moving 1 step at a time
        int left=help(n-1,cost , tar);

      //moving 2 steps at a time
        int right=help(n-2, cost, tar);

      //if we reached target than we don't require cost to pay as we are already at destination
      //we have to pay if we want to move ahead
        if(n==tar) return min(left, right);

      //choose minimum cost and add it along with current steps cost
        int ans=min(left, right)+cost[n];
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return help(n, cost, n);        
    }
};

//We will get TLE for larger input so we have to use DP
//TC: O(2^N)
//SC: O(N)

//Memoization
class Solution {
public:
    int help(int n, vector<int>& cost, int tar, vector<int>& dp){
      //base case
        if(n<=1) return cost[n];

      //if cost is already calculated
        if(dp[n]!=-1) return dp[n];

      // 1 step 
        int left=help(n-1,cost , tar, dp);

      //jump 2 steps at a time
        int right=help(n-2, cost, tar, dp);

      //when we reach target then we don't need to pay as we are at destination just choose the minimum among them
        if(n==tar) return min(left, right);

      //else
        dp[n]=min(left, right)+cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, -1);
        return help(n, cost, n, dp);        
    }
};

//TC: O(N)
//SC: O(N)+O(N) .. stack and vector space

//Tabulation: bottom up approach
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1, -1);
       //base case converted 
       dp[0]=cost[0];
       dp[1]=cost[1];

      //traverse from step 2
       for(int i=2; i<n; i++){
         //if already calculated
           if(dp[i]!=-1) return dp[i];

         //1 step at a time
           int l=dp[i-1];

         //2 step at a time
           int r=dp[i-2];

         //f(n)=min(f(n-1), f(n-2))+cost[n]...Recurrence relation
           dp[i]= min(l,r)+cost[i];
           
       }  

      //we reached target
       return min(dp[n-1], dp[n-2]);    
    }
};

//TC:O(N)
//SC:O(N)..vector space

//Space optimization:

int minCostClimbingStairs(vector<int>& cost) {
//size of array
int n=cost.size();

//first previous
  int p1=cost[1];

//second previous
  int p2=cost[0];

//traverse 
  for(int i=2; i<n; i++){
    int curr=min(p1, p2)+cost[i];
    p2=p1;
    p1=curr;
}
return min(p1, p2);
}

//TC:O(N)
//SC:O(1) ..as we are storing in variable
