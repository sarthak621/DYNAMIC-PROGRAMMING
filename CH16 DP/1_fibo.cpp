#include<iostream>
#include<vector>
using namespace std;


// // MEMOIZATION

// int f(int n , vector<int>&dp){
//     //base case
//     if(n<=1) return n;

//     if(dp[n]!=-1) return dp[n];

//     return dp[n]=f(n-1,dp)+f(n-2,dp);

// }

// int main(){ 
//     int n;
//     cin>>n;
     
//     //declare the size of the vectors
//     vector<int>dp(n+1 ,-1); //dp of size n and each of having values -1
     
//     cout<<f(n,dp);
//     return 0;
// }



// //TABULATION

// int main(){
//     int n;
//     cin>>n;

//     // declare the size of the vectors
//     vector<int>dp(n+1 ,-1); //dp of size n and each of having values -1

//     dp[0]=0;
//     dp[1]=1;

//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }

//     cout<<dp[n];

// }



//TABULATION and SPACE OPTIMIZATION

int main(){
    int n;
    cin>>n;

    // declare the size of the vectors
    // vector<int>dp(n+1 ,-1); //dp of size n and each of having values -1

    int prev2=0;
    int prev=1;

    for(int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi; 
    }

    cout<<prev; //prev holds the value of curi thats why we have return the prev
  
}