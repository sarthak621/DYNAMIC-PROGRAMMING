//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int f(int ind,int n,vector<int> &price,vector<vector<int>>&dp){
        //base case
        if(ind==0){
            //that means we are at the index 1
            if(ind<n)
            return n*price[0];
            
            else return 0;
        }
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int notTake=0+f(ind-1,n,price,dp);
        
        int take=-1e9;
        int rodLength=ind+1;
        if(rodLength<=n) take=price[ind]+f(ind,n-rodLength,price,dp);
        
        return dp[ind][n]=max(notTake,take);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return f(n-1,n,price,dp);  //last index, leng of rod, array of price
    }
};






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











//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends