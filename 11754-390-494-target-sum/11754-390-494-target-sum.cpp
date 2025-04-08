class Solution {
public:

//reffereing from [dp 18]

   int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += arr[i];
        }

       
        if((totSum - d) < 0 || (totSum - d) % 2 != 0) return 0;

        int target = (totSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // return f(n - 1, target, arr, dp);
        
        // base cases
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
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

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};