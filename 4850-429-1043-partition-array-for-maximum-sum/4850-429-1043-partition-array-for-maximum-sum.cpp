class Solution {
public:
   
   //tabulation

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        
        vector<int>dp(n+1,0);
        // return f(0,n,arr,k,dp);

        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxi=-1e9;
            int maxAns=-1e9;
    
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
    
                int sum=len*maxi + dp[j+1];
                maxAns=max(maxAns,sum);
            }
             dp[i]=maxAns;
        }

        return dp[0];
    }
};



//    //memoization
//     int f(int i,int n, vector<int>& arr, int k,vector<int>&dp){
//         //base case 
//         if(i==n) return 0;

//         if(dp[i]!=-1) return dp[i];

//         //r.r front partition
//         int len=0;
//         int maxi=-1e9;
//         int maxAns=-1e9;

//         for(int j=i;j<min(n,i+k);j++){
//             len++;
//             maxi=max(maxi,arr[j]);

//             int sum=len*maxi + f(j+1,n,arr,k,dp);
//             maxAns=max(maxAns,sum);
//         }
//         return dp[i]=maxAns;

//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n= arr.size();
        
//         vector<int>dp(n+1,-1);
//         return f(0,n,arr,k,dp);
//     }



// //R.R
//     int f(int i,int n, vector<int>& arr, int k){
//         //base case 
//         if(i==n) return 0;

//         //r.r front partition
//         int len=0;
//         int maxi=-1e9;
//         int maxAns=-1e9;

//         for(int j=i;j<min(n,i+k);j++){
//             len++;
//             maxi=max(maxi,arr[j]);

//             int sum=len*maxi + f(j+1,n,arr,k);
//             maxAns=max(maxAns,sum);
//         }
//         return maxAns;

//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n= arr.size();

//         return f(0,n,arr,k);
//     }