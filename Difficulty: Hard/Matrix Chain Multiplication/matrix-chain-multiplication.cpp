//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    // int f(int i,int j, vector<int> &arr,vector<vector<int>>&dp){
    //     //base case
    //     if(i==j) return 0;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     //R.R
    //     int mini=1e9;
    //     for(int k=i;k<j;k++){
    //         int steps=arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
    //         mini=min(mini,steps);
    //     }
        
    //     return dp[i][j]= mini;
    // }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // return f(1,n-1,arr,dp);
        
        //1.base case
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        
        //2. for loops
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
               int mini=1e9;
               for(int k=i;k<j;k++){
               int steps=arr[i-1]*arr[k]*arr[j] + dp[i][k]+ dp[k+1][j];
               mini=min(mini,steps);
            }
            dp[i][j]= mini;
          }
          
        }
        
        return dp[1][n-1];
    }
    
};



// // memoization
//     int f(int i,int j, vector<int> &arr,vector<vector<int>>&dp){
//         //base case
//         if(i==j) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         //R.R
//         int mini=1e9;
//         for(int k=i;k<j;k++){
//             int steps=arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
//             mini=min(mini,steps);
//         }
        
//         return dp[i][j]= mini;
//     }
//     int matrixMultiplication(vector<int> &arr) {
//         // code here
//         int n=arr.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return f(1,n-1,arr,dp);
//     }





// //recursive
//      int f(int i,int j, vector<int> &arr){
//         //base case
//         if(i==j) return 0;
        
//         //R.R
//         int mini=1e9;
//         for(int k=i;k<j;k++){
//             int steps=arr[i-1]*arr[k]*arr[j] + f(i,k,arr) + f(k+1,j,arr);
//             mini=min(mini,steps);
//         }
        
//         return mini;
//     }
//     int matrixMultiplication(vector<int> &arr) {
//         // code here
//         int n=arr.size();
        
//         return f(1,n-1,arr);
//     }




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends