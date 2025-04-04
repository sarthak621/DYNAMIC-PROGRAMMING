class Solution {
  public:
  
  //space optimization 
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        
        int n=arr.size();
        
        vector<int>prev(4,-1);
        
        prev[0]=max(arr[0][1],arr[0][2]);
        prev[1]=max(arr[0][0],arr[0][2]);
        prev[2]=max(arr[0][0],arr[0][1]);
        prev[3]=max({arr[0][0],arr[0][1],arr[0][2]});
        
        for(int day=1;day<n;day++){
            vector<int>temp(4,0);
            for(int task=0;task<4;task++){
                // dp[day][task]=0;
                temp[task]=0;
                
                for(int i=0;i<3;i++){
                   if(i!=task){
                       int points=arr[day][i]+ prev[i];
                    //   dp[day][task]=max(dp[day][task],points);
                         temp[task]=max(temp[task],points);
                   }
                }
            }
            prev=temp;
        }
        return prev[3];
    }
};


// ////tabulation 
    // int maximumPoints(vector<vector<int>>& arr) {
    //     // Code here
        
    //     int n=arr.size();
        
    //     vector<vector<int>>dp(n,vector<int>(4,-1));
        
    //     dp[0][0]=max(arr[0][1],arr[0][2]);
    //     dp[0][1]=max(arr[0][0],arr[0][2]);
    //     dp[0][2]=max(arr[0][0],arr[0][1]);
    //     dp[0][3]=max({arr[0][0],arr[0][1],arr[0][2]});
        
    //     for(int day=1;day<n;day++){
    //         for(int task=0;task<4;task++){
    //             dp[day][task]=0;
                
    //             for(int i=0;i<3;i++){
    //               if(i!=task){
    //                   int points=arr[day][i]+ dp[day-1][i];
    //                   dp[day][task]=max(dp[day][task],points);
    //               }
    //             }
    //         }
    //     }
    //     return dp[n-1][3];
    // }



// //memoization
//     int solveGeekTraining(int days,int task,vector<vector<int>>& arr,vector<vector<int>>&dp){
        
//         //base case
//         if(days==0){
//             int maxi=0;
//             for(int i=0;i<3;i++){
//                 if(i!=task){
//                     maxi=max(maxi,arr[0][i]);
//                 }
//             }
//             return maxi;
//         }
        
        
//         //
//         if(dp[days][task]!=-1) return dp[days][task];
        
//         int maxi=0;
//         for(int i=0;i<3;i++){
//             if(i!=task){
//                 int points=arr[days][i]+ solveGeekTraining(days-1,i,arr,dp);
//                 maxi=max(maxi,points);
//             }
//         }
        
//         return dp[days][task]=maxi;
        
        
//     }
//     int maximumPoints(vector<vector<int>>& arr) {
//         // Code here
        
//         int n=arr.size();
        
//         vector<vector<int>>dp(n,vector<int>(4,-1));
//         return solveGeekTraining(n-1,3,arr,dp);  //n-1 bcoz we want days as 1 less as it is 0 based indexing
//     }
// };




//recursive


// int solveGeekTraining(int days,int task,vector<vector<int>>& arr){
        
//         //base case
//         if(days==0){
//             int maxi=0;
//             for(int i=0;i<3;i++){
//                 if(i!=task){
//                     maxi=max(maxi,arr[0][i]);
//                 }
//             }
//             return maxi;
//         }
        
        
//         //
//         int maxi=0;
//         for(int i=0;i<3;i++){
//             if(i!=task){
//                 int points=arr[days][i]+ solveGeekTraining(days-1,i,arr);
//                 maxi=max(maxi,points);
//             }
//         }
        
//         return maxi;
        
        
//     }
//     int maximumPoints(vector<vector<int>>& arr) {
//         // Code here
//         int n=arr.size();
//         return solveGeekTraining(n-1,3,arr);  //n-1 bcoz we want days as 1 less as it is 0 based indexing
//     }
