class Solution {
public:
    //space optimization

    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<int>prev(n,0);
        
        // dp[0][0]=1;

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    // dp[0][0]=1;
                    
                    curr[j]=1;
                    continue;

                }    

                int left=0,up=0;

                if(j>0) left=curr[j-1];
                if(i>0) up=prev[j];


                // dp[i][j]=left+up;
                curr[j]=up+left;

            }

            prev=curr;
        }

        return prev[n-1];
    }
};


// //tabulation [T.C.->O(n*m) S.C-->O(n*m)]

//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         dp[0][0]=1;

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) {
//                     // dp[0][0]=1;
//                     continue;
//                 }    

//                 int left=0,up=0;

//                 if(j>0) left=dp[i][j-1];
//                 if(i>0) up=dp[i-1][j];

//                 dp[i][j]=left+up;

//             }
//         }

//         return dp[m-1][n-1];
//     }
// };



// //MEMOIZATION [T.C.->O(n*m) S.C-->O((n-1)(m-1))+O(n*m)]

//     int f(int i , int j,vector<vector<int>>&dp){
//         //base cases
//         if(i==0 && j==0) return 1;

//         //out of range case
//         if(i<0 || j<0) return 0;

//         //recursion

//         if( dp[i][j]!=-1) return dp[i][j];
        

//         int left=f(i,j-1,dp);
//         int up=f(i-1,j,dp);

//         return dp[i][j]=left+up;
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return f(m-1,n-1,dp);
//     }




// //RECURSIVE -->>T.L.E [T.C->2^m*n, S.C O(m-1)(n-1) {path length}]

//     int f(int i , int j){
//         //base cases
//         if(i==0 && j==0) return 1;

//         //out of range case
//         if(i<0 || j<0) return 0;

//         //recursion
        

//         int left=f(i,j-1);
//         int up=f(i-1,j);

//         return left+up;
//     }

//     int uniquePaths(int m, int n) {
//         return f(m-1,n-1);
//     }