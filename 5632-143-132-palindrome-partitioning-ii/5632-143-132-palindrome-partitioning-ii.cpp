class Solution {
public:
    //tabulation
    bool isPali(int i,int j, string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;

            i++;
            j--;
        }
        return true;
    }


    int minCut(string s) {
        int n=s.size();
        
        vector<int>dp(n+1,0);
        // return f(0,n,s,dp)-1;
        dp[n]=0;

        //for loops
        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int j=i;j<n;j++){
                if(isPali(i,j,s)){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
         dp[i]=mini;
        }
        return dp[0]-1;
    }
};



//memoization
    // bool isPali(int i,int j, string &s){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;

    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    // int f(int i,int n, string &s,vector<int>&dp){
    //     if(i==n) return 0;
        
    //     if(dp[i]!=-1) return dp[i];
    //     //r.r
    //     int mini=1e9;
    //     for(int j=i;j<n;j++){
    //         if(isPali(i,j,s)){
    //             int cost=1+f(j+1,n,s,dp);
    //             mini=min(mini,cost);
    //         }
    //     }
    //     return dp[i]=mini;
    // }
    // int minCut(string s) {
    //     int n=s.size();
        
    //     vector<int>dp(n+1,-1);
    //     return f(0,n,s,dp)-1;
    // }







// recursive

    // bool isPali(int i,int j, string &s){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;

    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    // int f(int i,int n, string &s){
    //     if(i==n) return 0;

    //     //r.r
    //     int mini=1e9;
    //     for(int j=i;j<n;j++){
    //         if(isPali(i,j,s)){
    //             int cost=1+f(j+1,n,s);
    //             mini=min(mini,cost);
    //         }
    //     }
    //     return mini;
    // }
    // int minCut(string s) {
    //     int n=s.size();

    //     return f(0,n,s)-1;