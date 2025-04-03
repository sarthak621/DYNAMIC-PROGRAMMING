class Solution {
  public:
  

   
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        int n=arr.size();         //syntax
        vector<int>dp(n,-1);     //syntax
        dp[0]=0;                 //syntax
        
        
        
         
        for(int i=1;i<n;i++){        //syntax
            int minSteps=INT_MAX;     
            for(int j=1;j<=k;j++){
              if(i-j>=0){
                  int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                  minSteps=min(minSteps,jump);
              }
              
              dp[i]=minSteps;   //syntax
            }
        }
        
        return dp[n-1];   //suntax
    }
};



//              //memoization
//     int minimialCostSolve(int k, vector<int>& arr,int index,vector<int>&dp ){
//          if(index==0) return 0;
//          if(dp[index]!=-1) return dp[index];
         
//          int min_steps=INT_MAX;
         
//          //j->jumps
//          for(int j=1;j<=k;j++){
//              if(index-j>=0){
//                  int jump=minimialCostSolve(k,arr,index-j,dp)+abs(arr[index]-arr[index-j]);
                 
//                  min_steps=min(min_steps,jump);
//              }
//          }
         
//          return dp[index]=min_steps;
//     }
   
//     int minimizeCost(int k, vector<int>& arr) {
//         // Code here
        
//         int n=arr.size();
//         vector<int>dp(n+1,-1);
        
//         return minimialCostSolve(k,arr,n-1,dp);
//     }
    
    
    
    

//    // RECURSIVE
// int minimialCostSolve(int k, vector<int>& arr,int n ){
//          if(n==0) return 0;
         
//          int min_steps=INT_MAX;
         
//          //j->jumps
//          for(int j=1;j<=k;j++){
//              if(n-j>=0){
//                  int jump=minimialCostSolve(k,arr,n-j)+abs(arr[j]-arr[n-j]);
                 
//                  min_steps=min(min_steps,jump);
//              }
//          }
         
//          return min_steps;
//     }
   
//     int minimizeCost(int k, vector<int>& arr) {
//         // Code here
        
//         int n=arr.size();
        
//         return minimialCostSolve(k,arr,n);
//     }

