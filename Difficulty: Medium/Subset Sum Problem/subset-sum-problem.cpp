//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
  //memoization
    bool f(int index,vector<int>& arr, int target,vector<vector<int>>&dp){
        //base cases
        
        //1. when we reachead  target 0 return the true
        if(target==0) return true;
        
        //2. when we reachead at the index 0 then we check whether our 0th index is euual to target or not
        if(index==0) return arr[0]==target;
        
        if(dp[index][target]!=-1) return dp[index][target];
        
        //recursion
        bool notTake=  f(index-1,arr,target,dp);
        
        bool take= false;
        
        if(target>=arr[index]){
            take=f(index-1,arr,target-arr[index],dp);
        }
        
        return dp[index][target]=notTake||take;
        
        
        
        
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        
        
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};


//recursion

//  bool f(int index,vector<int>& arr, int target){
//         //base cases
        
//         //1. when we reachead  target 0 return the true
//         if(target==0) return true;
        
//         //2. when we reachead at the index 0 then we check whether our 0th index is euual to target or not
//         if(index==0) return arr[0]==target;
        
//         //recursion
//         bool notTake=  f(index-1,arr,target);
        
//         bool take= false;
        
//         if(target>=arr[index]){
//             take=f(index-1,arr,target-arr[index]);
//         }
        
//         return notTake||take;
        
        
        
        
        
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         // code here
        
//         int n=arr.size();
//         return f(n-1,arr,sum);
//     }



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends