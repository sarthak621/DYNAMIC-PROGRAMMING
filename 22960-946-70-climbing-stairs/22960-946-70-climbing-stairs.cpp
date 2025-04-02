class Solution {
public:

    //memoization approach
     int solveClimbStairs(int n,vector<int>&dp){
        if(n==0 || n==1) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=solveClimbStairs(n-1,dp)+solveClimbStairs(n-2,dp);
     }

    int climbStairs(int n) {

        vector<int>dp(n+1 ,-1);
        return solveClimbStairs(n,dp);     
    }
};



// //recursive approach got TLE
// class Solution {
// public:
//     int climbStairs(int n) {
//         //this ques is similar to fibonacci
        
//         //base case
//         if(n==0) return 1;
//         if(n==1) return 1;

//         //Each time you can either climb 1 or 2 steps.
//         return climbStairs(n-1)+climbStairs(n-2);


//     }
// };