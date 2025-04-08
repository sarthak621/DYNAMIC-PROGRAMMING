class Solution {
  public:
  
  
    //space optimization
    int cutRod(vector<int> &price) {
        // code here
        
        int n=price.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        //base case
        for(int i=0;i<=n;i++)  prev[i]=i*price[0];
        
        
        //for loops
        
        for(int ind=1;ind<n;ind++){
            for(int len=0;len<=n;len++){
                int notTake=0+prev[len];
        
                int take=-1e9;
                int rodLength=ind+1;
                if(rodLength<=len) take=price[ind]+curr[len - rodLength];
                
                 curr[len]=max(notTake,take);
            }
            prev=curr;
        }
        return prev[n];
    }
};



// //tabulation
//     int cutRod(vector<int> &price) {
//         // code here
        
//         int n=price.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,0));
        
//         //base case
//         for(int i=0;i<=n;i++)  dp[0][i]=i*price[0];
        
        
//         //for loops
        
//         for(int ind=1;ind<n;ind++){
//             for(int len=0;len<=n;len++){
//                 int notTake=0+dp[ind-1][len];
        
//                 int take=-1e9;
//                 int rodLength=ind+1;
//                 if(rodLength<=len) take=price[ind]+dp[ind][len - rodLength];
                
//                  dp[ind][len]=max(notTake,take);
//             }
//         }
//         return dp[n-1][n];
//     }











// //memoization
//     int f(int ind,int n,vector<int> &price,vector<vector<int>>&dp){
//         //base case
//         if(ind==0){
//             //that means we are at the index 1
//             if(ind<n)
//             return n*price[0];
            
//             else return 0;
//         }
        
//         if(dp[ind][n]!=-1) return dp[ind][n];
        
//         int notTake=0+f(ind-1,n,price,dp);
        
//         int take=-1e9;
//         int rodLength=ind+1;
//         if(rodLength<=n) take=price[ind]+f(ind,n-rodLength,price,dp);
        
//         return dp[ind][n]=max(notTake,take);
//     }
    
//     int cutRod(vector<int> &price) {
//         // code here
        
//         int n=price.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
//         return f(n-1,n,price,dp);  //last index, leng of rod, array of price
//     }






// //recursive
// int f(int ind,int n,vector<int> &price){
//         //base case
//         if(ind==0){
//             //that means we are at the index 1
//             if(ind<n)
//             return n*price[0];
            
//             else return 0;
//         }
        
//         int notTake=0+f(ind-1,n,price);
        
//         int take=-1e9;
//         int rodLength=ind+1;
//         if(rodLength<=n) take=price[ind]+f(ind,n-rodLength,price);
        
//         return max(notTake,take);
//     }
    
//     int cutRod(vector<int> &price) {
//         // code here
        
//         int n=price.size();
        
//         return f(n-1,n,price);  //last index, leng of rod, array of price
//     }
