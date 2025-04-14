//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1);

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp1[prev]>dp1[i]){ 
                    // writing this line {1+dp[prev]>dp[i]} to avoid updating the same values in dp[ind]
                    dp1[i]=1+dp1[prev];

                }
            }
            // maxi=max(maxi,dp[i]);
        }
        
        
        
        //backward lis
        vector<int>dp2(n,1);

        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){ 
                    // writing this line {1+dp[prev]>dp[i]} to avoid updating the same values in dp[ind]
                    dp2[i]=1+dp2[prev];

                }
            }
            
        }
        
        //bitonic
        int maxi=0;
        for(int i=0;i<n;i++){
            // maxi=max(maxi,dp1[i]+dp2[i]-1); //this will work when there is both inc. lis or dec. lis allow
            
            
        //A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence    
        if(dp1[i] > 1 && dp2[i] > 1){ // Ensure both increasing and decreasing
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
         }
            
        }
        
        return maxi;
        
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends