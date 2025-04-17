//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
// class Solution {
//   public:
    
//     #define ll long long  //defining a long long alias as ll
//     // const int mod = 1000000007;
//     const int mod = 1;
//     int f(int i,int j, int isTrue,string &s,vector<vector<vector<ll>>>&dp){
//         if(i>j) return 0;
//         if(i==j){
//             if(isTrue==1){
//                 return s[i]=='T';
//             }
//             else{
//                 // if isTrue=0
//                 return s[i]=='F';
//             }
//         }
        
//         if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
//         //R.R
//         ll ways=0;
//         for(int ind=i+1;ind<=j-1;ind=ind+2){
            
//             //left portion to be True
//             ll lT=f(i,ind-1,1,s,dp);
            
//             // left portion to be false
//             ll lF=f(i,ind-1,0,s,dp);
            
//             //right portion to be True
//             ll rT=f(ind+1,j,1,s,dp);
            
//             // right portion to be false
//             ll rF=f(ind+1,j,0,s,dp);
            
            
//             //& -> cases TT=T / TF=F /FT=F / FF=F
//             if(s[ind]=='&'){
//                 if(isTrue==1){
//                     ways= (ways+(lT*rT)%mod)%mod;
//                 }
//                 //Ham usko is liye add kar rahe hain kyunki jo usme function hai woh valid result de sakta hai
//                 else{
//                     ways= (ways+ (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod) %mod;
//                 }
//             }
            
//             else if(s[ind]== '|'){
//                 if(isTrue==1){
//                     ways= (ways+ (lT*rT)%mod + (lF*rT)%mod + (lT*rF)%mod ) %mod;
//                 }
//                 else{
//                     ways= (ways+(lF*rF)%mod)%mod;
//                 }
//             }
            
//             else if(s[ind]== '^'){
//                 // ^ ->> TT=F FF=T TF=F FT=T
//                 if(isTrue==1){
//                      ways= (ways+ (lF*rT)%mod + (lT*rF)%mod ) %mod;
//                 }
//                 else{
//                     ways= (ways+ (lT*rT)%mod + (lF*rF)%mod ) %mod;
//                 }
//             }
            
//         }
        
//         return dp[i][j][isTrue]=ways;
//     }
    
//     int countWays(string &s) {
//         // code here
//         int n=s.size();
        
//         vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
        
//         return (int)(f(0, n-1, 1, s, dp) % mod); //i=0 and j=n-1 , isTrue=1 , s string 
//     }
// };

class Solution {
  public:
    
    #define ll long long  //defining a long long alias as ll
   

    int f(int i, int j, int isTrue, string &s, vector<vector<vector<ll>>>& dp) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue == 1) {
                return s[i] == 'T';
            } else {
                // if isTrue = 0
                return s[i] == 'F';
            }
        }
        
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        ll ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            // left portion to be True
            ll lT = f(i, ind - 1, 1, s, dp);
            
            // left portion to be false
            ll lF = f(i, ind - 1, 0, s, dp);
            
            // right portion to be True
            ll rT = f(ind + 1, j, 1, s, dp);
            
            // right portion to be false
            ll rF = f(ind + 1, j, 0, s, dp);
            
            // & -> cases TT = T / TF = F / FT = F / FF = F
            if (s[ind] == '&') {
                if (isTrue == 1) {
                    ways = (ways + (lT * rT) ) ;
                } else {
                    ways = (ways + (lF * rT) + (lT * rF)  + (lF * rF) ) ;
                }
            }
            
            // | -> cases TT = T / TF = T / FT = T / FF = F
            else if (s[ind] == '|') {
                if (isTrue == 1) {
                    ways = (ways + (lT * rT)  + (lF * rT)  + (lT * rF) );
                } else {
                    ways = (ways + (lF * rF) ) ;
                }
            }
            
            // ^ -> cases TT = F / FF = T / TF = F / FT = T
            else if (s[ind] == '^') {
                if (isTrue == 1) {
                    ways = (ways + (lF * rT) + (lT * rF) );
                } else {
                    ways = (ways + (lT * rT)+ (lF * rF)) ;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(string &s) {
        int n = s.size();
        
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
        
        return (int)(f(0, n - 1, 1, s, dp) ); // i = 0 and j = n - 1, isTrue = 1, s string
    }
};





//recursive

// class Solution {
//   public:
    
//     #define ll long long  //defining a long long alias as ll
//     const int mod = 1000000007;
//     int f(int i,int j, int isTrue,string &s){
//         if(i>j) return 0;
//         if(i==j){
//             if(isTrue==1){
//                 return s[i]=='T';
//             }
//             else{
//                 // if isTrue=0
//                 return s[i]=='F';
//             }
//         }
        
//         //R.R
//         int ways=0;
//         for(int ind=i+1;ind<=j-1;ind=ind+2){
            
//             //left portion to be True
//             ll lT=f(i,ind-1,1,s);
            
//             // left portion to be false
//             ll lF=f(i,ind-1,0,s);
            
//             //right portion to be True
//             ll rT=f(ind+1,j,1,s);
            
//             // right portion to be false
//             ll rF=f(ind+1,j,0,s);
            
            
//             //& -> cases TT=T / TF=F /FT=F / FF=F
//             if(s[ind]=='&'){
//                 if(isTrue==1){
//                     ways= (ways+(lT*rT)%mod)%mod;
//                 }
//                 //Ham usko is liye add kar rahe hain kyunki jo usme function hai woh valid result de sakta hai
//                 else{
//                     ways= (ways+ (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod) %mod;
//                 }
//             }
            
//             else if(s[ind]== '|'){
//                 if(isTrue==1){
//                     ways= (ways+ (lT*rT)%mod + (lF*rT)%mod + (lT*rF)%mod ) %mod;
//                 }
//                 else{
//                     ways= (ways+(lF*rF)%mod)%mod;
//                 }
//             }
            
//             else if(s[ind]== '^'){
//                 // ^ ->> TT=F FF=T TF=F FT=T
//                 if(isTrue==1){
//                      ways= (ways+ (lF*rT)%mod + (lT*rF)%mod ) %mod;
//                 }
//                 else{
//                     ways= (ways+ (lT*rT)%mod + (lF*rF)%mod ) %mod;
//                 }
//             }
            
//         }
        
//         return ways;
//     }
    
//     int countWays(string &s) {
//         // code here
//         int n=s.size();
        
//         return f(0,n-1,1,s); // i=0 and j=n-1 , isTrue=1 , s string 
//     }


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends