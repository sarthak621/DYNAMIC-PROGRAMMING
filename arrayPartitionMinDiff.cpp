// Array partition with minimum difference {coding ninja}

int minSubsetSumDifference(vector<int>& arr, int n)
{

        // // tabulation
        // int n=nums.size();

        int totalSum=0;  //now totalSum is our target
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        
        vector<vector<bool>>dp(n+1,vector<bool>(totalSum+1,false));
        
        
        //base cases
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(arr[0] <= totalSum) dp[0][arr[0]]=true;
        
        
        //form the nested loops
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=totalSum;j++){
                 //recursion
                 bool notTake=  dp[i-1][j];
                 
                 bool take= false;
                 
                 if(j>=arr[i]){
                     take= dp[i-1][j-arr[i]];
                 }
                 
                 dp[i][j]=notTake||take;
            }
        }
        
        // return dp[n-1][sum];

        //ans= dp[n-1][totalSum]

        int mini=1e9;

        for(int sum=0;sum<=totalSum;sum++){
            if(dp[n-1][sum]==true){
                int diff=abs((totalSum-sum)-sum);
                
                mini=min(mini,diff);
            }
        }

        return mini;




}
