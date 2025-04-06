class Solution {
  public:
  
  
  
        
    // space optimization
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here

        int n=arr.size();
        
        vector<bool>prev(sum+1,0);
        vector<bool>curr(sum+1,0);
        
        
        //base cases
        // for(int i=0;i<n;i++){
        //     dp[i][0]=true;
        // }
        
        // dp[0][arr[0]]=true;
        
        prev[0]=curr[0]=true;
        
        prev[arr[0]]=true;
        
        //form the nested loops
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                 //recursion
                 bool notTake=  prev[j];
                 
                 bool take= false;
                 
                 if(j>=arr[i]){
                     take= prev[j-arr[i]];
                 }
                 
                 curr[j]=notTake||take;
            }
            prev=curr;
        }
        
        return prev[sum];
    }
};



// // // tabulation
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         // code here

//         int n=arr.size();
        
//         vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
        
//         //base cases
//         for(int i=0;i<n;i++){
//             dp[i][0]=true;
//         }
        
//         dp[0][arr[0]]=true;
        
        
//         //form the nested loops
        
        
//         for(int i=1;i<n;i++){
//             for(int j=1;j<=sum;j++){
//                  //recursion
//                  bool notTake=  dp[i-1][j];
                 
//                  bool take= false;
                 
//                  if(j>=arr[i]){
//                      take= dp[i-1][j-arr[i]];
//                  }
                 
//                  dp[i][j]=notTake||take;
//             }
//         }
        
//         return dp[n-1][sum];
//     }











// // //memoization
//     bool f(int index,vector<int>& arr, int target,vector<vector<int>>&dp){
//         //base cases
        
//         //1. when we reachead  target 0 return the true
//         if(target==0) return true;
        
//         //2. when we reachead at the index 0 then we check whether our 0th index is euual to target or not
//         if(index==0) return arr[0]==target;
        
//         if(dp[index][target]!=-1) return dp[index][target];
        
//         //recursion
//         bool notTake=  f(index-1,arr,target,dp);
        
//         bool take= false;
        
//         if(target>=arr[index]){
//             take=f(index-1,arr,target-arr[index],dp);
//         }
        
//         return dp[index][target]=notTake||take;
        
        
        
        
        
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         // code here
        
        
        
//         int n=arr.size();
        
//         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
//         return f(n-1,arr,sum,dp);
//     }
// };




//recursion

//  bool f(int index,vector<int>& arr, int target){
//         //base cases
        
//         //1. when we reachead  target 0 return the true
//         if(target==0) return true;
        
//         //2. when we reachead at the index 0 then we check whether our 0th index is euual to target or not
//         if(index==0) return arr[0]==target;
        
//         //recursion
//         bool notTake=  f(index-1,arr,target);
        
//         bool take= false;
        
//         if(target>=arr[index]){
//             take=f(index-1,arr,target-arr[index]);
//         }
        
//         return notTake||take;
        
        
        
        
        
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         // code here
        
//         int n=arr.size();
//         return f(n-1,arr,sum);
//     }
