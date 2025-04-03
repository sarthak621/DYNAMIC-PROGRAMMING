class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        
        //TSPACE OPTIMIZATION
        int n=height.size();
        // vector<int>dp(n,-1);
        int prev=0;
        int prev2=0;
        
        // dp[0]=0;
        
        for(int i=1;i<n;i++){
            int fs=prev+abs(height[i]-height[i-1]);
            
            int ss=INT_MAX;
            if (i>1){
                ss=prev2+abs(height[i]-height[i-2]);
                
            }
            
             int curi=min(fs,ss);
             prev2=prev;
             prev=curi;
        }
        
        return prev;
        
    }


//tabulation

// int minCost(vector<int>& height) {
//         // Code here
        
//         //TABULATION 
//         int n=height.size();
//         vector<int>dp(n,-1);
        
//         dp[0]=0;
        
//         for(int i=1;i<n;i++){
//             int fs=dp[i-1]+abs(height[i]-height[i-1]);
            
//             int ss=INT_MAX;
//             if (i>1){
//                 ss=dp[i-2]+abs(height[i]-height[i-2]);
                
//             }
            
//              dp[i]=min(fs,ss);
//         }
        
//         return dp[n-1];
        
//     }


// //MEMOIZATION
//     int frogJumpSolve(vector<int>& height,vector<int>&dp,int index ){
//         if(index==0) return 0;
//         if(dp[index]!=-1) return dp[index];
//         int left;
//         int right=INT_MAX;
        
//         left=frogJumpSolve(height,dp,index-1)+abs(height[index]-height[index-1]);
//         if(index>1){
//             right=frogJumpSolve(height,dp,index-2)+abs(height[index]-height[index-2]);
//         }
//         return dp[index]=min(left,right);
        
//     }
//     int minCost(vector<int>& height) {
//         // Code here
//         int n=height.size();
//         vector<int>dp(n+1,-1);
//         return frogJumpSolve(height,dp,n-1);
//     }
