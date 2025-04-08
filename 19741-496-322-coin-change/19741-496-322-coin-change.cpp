class Solution {
public:
    //space optimization
   
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();

        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);

        
        //base cases
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=target/coins[0];
            else prev[target]=1e9;
        }
        
        //for loops
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
              //pick //not pick

              int notPick=prev[target];
              int pick=1e9; //int max
            //   if(target>=coins[ind]) pick=1+prev[target-coins[ind]];

            // using **prev** even when you're picking the current coin — this is not correct in an unbounded knapsack problem.
              if(target>=coins[ind]) pick=1+curr[target-coins[ind]];  


              curr[target]=min(pick,notPick);
            }
            prev=curr;
        }
        int res=prev[amount];
        return (res >= 1e9) ? -1 : res;
        
    }
};


//  //tabulation
   
//     int coinChange(vector<int>& coins, int amount) {
        
//         int n=coins.size();

//         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
//         //base cases
//         for(int target=0;target<=amount;target++){
//             if(target%coins[0]==0) dp[0][target]=target/coins[0];
//             else dp[0][target]=1e9;
//         }
        
//         //for loops
//         for(int ind=1;ind<n;ind++){
//             for(int target=0;target<=amount;target++){
//               //pick //not pick

//               int notPick=dp[ind-1][target];
//               int pick=1e9; //int max
//               if(target>=coins[ind]) pick=1+dp[ind][target-coins[ind]];

//               dp[ind][target]=min(pick,notPick);
//             }
//         }
//         int res=dp[n-1][amount];
//         return (res >= 1e9) ? -1 : res;
        
//     }





//     //memoization
//     int f(int ind,int target,vector<int>& coins,vector<vector<int>>&dp){
//         //base cases
        
//         if(ind==0){
//             if(target%coins[ind]==0) return target/coins[ind];
//             else return 1e9;
//         }

//         if(dp[ind][target]!=-1) return dp[ind][target]; 

//         //pick //not pick

//         int notPick=f(ind-1,target,coins,dp);
//         int pick=1e9; //int max
//         if(target>=coins[ind]) pick=1+f(ind,target-coins[ind],coins,dp); //1 bcoz we need to count no. of coins and same index bcoz we have infinite supply of coins

//         return dp[ind][target]=min(pick,notPick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
        
//         int n=coins.size();

//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
//         int res= f(n-1,amount,coins,dp);
//         return (res >= 1e9) ? -1 : res;
//     }
// };





// //recursion
// int f(int ind,int target,vector<int>& coins){
//         //base cases
//         if(ind==0){
//             if(target%coins[ind]==0) return target/coins[ind];
//             else return -1;
//         }

//         //pick //not pick

//         int notPick=f(ind-1,target,coins);
//         int pick=1e9; //int max
//         if(target>=coins[ind]) pick=1+f(ind,target-coins[ind],coins); //1 bcoz we need to count no. of coins and same index bcoz we have infinite supply of coins

//         return min(pick,notPick);
//     }
//     int coinChange(vector<int>& coins, int amount) {
        
//         int n=coins.size();
//                int res= f(n-1,amount,coins,dp);
        // return (res >= 1e9) ? -1 : res;
//     }