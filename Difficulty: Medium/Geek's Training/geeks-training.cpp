//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
   //memoization
    int solveGeekTraining(int days,int task,vector<vector<int>>& arr,vector<vector<int>>&dp){
        
        //base case
        if(days==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=task){
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        
        
        //
        if(dp[days][task]!=-1) return dp[days][task];
        
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=task){
                int points=arr[days][i]+ solveGeekTraining(days-1,i,arr,dp);
                maxi=max(maxi,points);
            }
        }
        
        return dp[days][task]=maxi;
        
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solveGeekTraining(n-1,3,arr,dp);  //n-1 bcoz we want days as 1 less as it is 0 based indexing
    }
};




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


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends