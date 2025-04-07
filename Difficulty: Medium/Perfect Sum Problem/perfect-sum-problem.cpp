class Solution {
  public:
  
  
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        

         for(int i=0;i<n;i++) dp[i][0]=1;
         
         //to handle target=0
         //arr = {0}, target = 0   -->> then the subset is 1 for 0 and 1 for {}
         if (arr[0] == 0)
             dp[0][0] = 2;  // We can either include or exclude the 0
         
         //if arr = {5} and target = 0 then subset is only 1 i.e. {}
         else
             dp[0][0] = 1;  // Only one way: exclude the first element
         
         if(arr[0]!=0 && target>=arr[0]) dp[0][arr[0]]=1;
         
         
         for(int i=1;i<n;i++){
             for(int j=0;j<=target;j++){
                 // if we start from j=1 we are missed with the case when sum is 0
                 int notPick= dp[i-1][j];
                 
                 int pick=0;
                 if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
                 
                 dp[i][j]=pick+notPick;
             }
         }
         
         return dp[n-1][target];
       
    }
};

//  // memoization
//     int f(int ind , int target ,vector<int>& arr,vector<vector<int>>&dp){
//         // if(target==0) return 1;
//         // if(ind==0) return arr[0]==target;
//         if(ind == 0) {
//     if (target == 0 && arr[0] == 0) return 2; // pick or not pick the 0
//     if (target == 0 || target == arr[0]) return 1;
//     return 0;
// }
        
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         int notPick= f(ind-1,target,arr,dp);
        
//         int pick=0;
//         if(target>=arr[ind]) pick=f(ind-1,target-arr[ind],arr,dp);
        
//         return dp[ind][target]=pick+notPick;
//     }  
    
//     int perfectSum(vector<int>& arr, int target) {
//         // code here
        
//         int n=arr.size();
        
//         vector<vector<int>>dp(n,vector<int>(target+1,-1));
//          return f(n-1,target,arr,dp);
//     }
