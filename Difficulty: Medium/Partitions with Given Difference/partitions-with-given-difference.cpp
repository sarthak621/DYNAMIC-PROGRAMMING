//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int f(int ind , int target ,vector<int>& arr,vector<vector<int>>&dp){
        //base cases
        // if(target==0) return 1;
        if(ind==0){
            if(arr[0]==0 && target==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notPick=f(ind-1,target,arr,dp);
        int pick=0;
        if(target>=arr[ind]) pick=f(ind-1,target-arr[ind],arr,dp);
        
        return dp[ind][target]=pick+notPick;
    }
  
  
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totSum = 0;
        for(int i = 0; i < n; i++){
            totSum += arr[i];
        }

       
        if((totSum - d) < 0 || (totSum - d) % 2 != 0) return 0;

        int target = (totSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends