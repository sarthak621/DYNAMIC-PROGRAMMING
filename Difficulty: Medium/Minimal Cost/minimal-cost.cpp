//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int minimialCostSolve(int k, vector<int>& arr,int index,vector<int>&dp ){
         if(index==0) return 0;
         if(dp[index]!=-1) return dp[index];
         
         int min_steps=INT_MAX;
         
         //j->jumps
         for(int j=1;j<=k;j++){
             if(index-j>=0){
                 int jump=minimialCostSolve(k,arr,index-j,dp)+abs(arr[index]-arr[index-j]);
                 
                 min_steps=min(min_steps,jump);
             }
         }
         
         return dp[index]=min_steps;
    }
   
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        int n=arr.size();
        vector<int>dp(n+1,-1);
        
        return minimialCostSolve(k,arr,n-1,dp);
    }
};



   // RECURSIVE
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




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends