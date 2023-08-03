//CodeStudio: Frog Jump
//LINK: https://bit.ly/3JPcoOx


//Recursive approach
#include <bits/stdc++.h> 
int help(int n,vector<int> &heights){
    //base case
    if(n==0)return 0;

    //recursive call one step hop
    int l=help(n-1, heights)+ abs(heights[n]-heights[n-1]);
    int r=INT_MAX;

    //recursive call 2 step hop but we can't do this for 1 as we will go to -1 
    //which is invalid therefore applied condtioncondition 
    if(n>1){
        r=help(n-2, heights)+ abs(heights[n]-heights[n-2]);
    }

    //return minimum val among left and right recursive call
    return min(l, r);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return help(n-1, heights);

}

//TC: O(2^n)
//SC: O(n)

//Memoization: Top to down approach

#include <bits/stdc++.h> 
int help(int n,vector<int> &heights, vector<int>& dp){
    //base case
    if(n==0)return 0;

    if(dp[n]!=-1) return dp[n];

    //recursive call one step hop
    int l=help(n-1, heights, dp)+ abs(heights[n]-heights[n-1]);
    int r=INT_MAX;

    //recursive call 2 step hop but we can't do this for 1 as we will go to -1 
    //which is invalid therefore applied condtioncondition 
    if(n>1){
        r=help(n-2, heights, dp)+ abs(heights[n]-heights[n-2]);
    }

    //return minimum val among left and right recursive call
    dp[n]= min(l, r);
    return dp[n];
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return help(n-1, heights, dp);

}

//TC: O(n)
//SC: O(n)+ O(n).. stack space and vector space

//Tabulation: bottom up approach

int frogJump(int n, vector<int> &heights)
{
   vector<int> dp(n+1, -1);

   //base case
   dp[0]=0;
   dp[1]=abs(heights[1]-heights[0]);

   //traverse
   for(int i=2; i<n; i++){

       // 1 hop
       int l=dp[i-1]+abs(heights[i]-heights[i-1]);

       //2 hop
       int r=dp[i-2]+abs(heights[i]-heights[i-2]);

       //consider min
       dp[i]=min(l,r);
   }
   return dp[n-1];

}

//TC: O(n)
//SC: O(n) ... vector space

//Space Optimization:

int frogJump(int n, vector<int> &heights)
{

   //base case
   int p2=0;
   int p1=0;

   //traverse
   for(int i=1; i<n; i++){

       // 1 hop
      int l=p1+abs(heights[i]-heights[i-1]);

       //2 hop
       int r=INT_MAX;
       if(i>1) r=p2+abs(heights[i]-heights[i-2]);

       //consider min
       int curr=min(l,r);
       p2=p1;
       p1=curr;

   }
   return p1;

}

//TC: O(n)
//SC: O(1)
