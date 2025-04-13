//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here

        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){ 
                    // writing this line {1+dp[prev]>dp[i]} to avoid updating the same values in dp[ind]
                    dp[i]=1+dp[prev];
                    //update the hash 
                    hash[i]=prev;
                }
            }
            // maxi=max(maxi,dp[i]);
        }

        //ab hame sabka dp and hash table pata chal gaya hai
        
        //pehle largest dp[i] ko store karo
        
        int ans=-1;
        int lastIndex=-1;
        
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIndex=i;
            }
        }
        
        //ab hame largest dp[i] and uska index pata hai
        
        vector<int>temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex]!= lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
         reverse(temp.begin(),temp.end());
         return temp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends