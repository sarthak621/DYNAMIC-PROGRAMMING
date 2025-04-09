class Solution {
public:

    //space opt
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);


        //base cases
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) prev[j]=0;

        // return f(n,m,text1,text2,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              
                if(text1[i-1]==text2[j-1])
                 curr[j]=1+prev[j-1];
        
                //not match
                else
                 curr[j]=0+max(prev[j],curr[j-1]);
        
                // dp[i][j]=max(match,notMatch);
            }
            prev=curr;
        }

        return prev[m];

    }
};

// //tabulation
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();

//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

//         //base cases
//         for(int i=0;i<=n;i++) dp[i][0]=0;
//         for(int j=0;j<=m;j++) dp[0][j]=0;

//         // return f(n,m,text1,text2,dp);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
              
//                 if(text1[i-1]==text2[j-1])
//                  dp[i][j]=1+dp[i-1][j-1];
        
//                 //not match
//                 else
//                  dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
        
//                 // dp[i][j]=max(match,notMatch);
//             }
//         }

//         return dp[n][m];

//     }





//      //memoization with shifting of index  

//     int f(int i,int j,string& text1, string& text2,vector<vector<int>>&dp){
//         //base case
//         if(i==0 || j==0) return 0;
          
//         if (dp[i][j]!=-1) return dp[i][j];
//         //r.r

//         //match
//         int match,notMatch=-1e9;
        
//         if(text1[i-1]==text2[j-1])
//          match=1+f(i-1,j-1,text1,text2,dp);

//         //not match
//         else
//          notMatch=0+max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));

//         return dp[i][j]=max(match,notMatch);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();

//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return f(n,m,text1,text2,dp);

//     }
// };











//  //memoization 

//     int f(int i,int j,string& text1, string& text2,vector<vector<int>>&dp){
//         //base case
//         if(i<0 || j<0) return 0;
          
//         if (dp[i][j]!=-1) return dp[i][j];
//         //r.r

//         //match
//         int match,notMatch=-1e9;
        
//         if(text1[i]==text2[j])
//          match=1+f(i-1,j-1,text1,text2,dp);

//         //not match
//         else
//          notMatch=0+max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));

//         return dp[i][j]=max(match,notMatch);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();

//         vector<vector<int>>dp(n,vector<int>(m+1,-1));
//         return f(n-1,m-1,text1,text2,dp);

//     }





// //recursrion

//     int f(int i,int j,string& text1, string& text2){
//         //base case
//         if(i<0 || j<0) return 0;

//         //r.r

//         //match
//         int match,notMatch=-1e9;
        
//         if(text1[i]==text2[j])
//          match=1+f(i-1,j-1,text1,text2);

//         //not match
//         else
//          notMatch=0+max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));

//         return max(match,notMatch);
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();


//         return f(n-1,m-1,text1,text2);

//     }