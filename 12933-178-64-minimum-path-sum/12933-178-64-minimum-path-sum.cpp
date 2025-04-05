class Solution {
public:
     
    //space optimization

    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(); //row 
        int n=grid[0].size();  //col
        
        vector<int>prev(n,-1);
        
        for(int i=0;i<m;i++){
            vector<int>curr(n,-1);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j]=grid[0][0];
                    continue;
                }

                int left=INT_MAX,up=INT_MAX;
                if(j>0) left=grid[i][j]+curr[j-1];
                if(i>0) up=grid[i][j]+prev[j];
                 
                curr[j]=min(left,up);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};

// //tabulation

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m= grid.size(); //row 
    //     int n=grid[0].size();  //col
        
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
        
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0){
    //                 dp[0][0]=grid[0][0];
    //                 continue;
    //             }

    //             int left=INT_MAX,up=INT_MAX;
    //             if(j>0) left=grid[i][j]+dp[i][j-1];
    //             if(i>0) up=grid[i][j]+dp[i-1][j];
                 
    //             dp[i][j]=min(left,up);
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }



//  //memoization
//     int f(int i, int j ,vector<vector<int>>& grid,vector<vector<int>>&dp){
//         if(i==0 && j==0) return grid[i][j];
//         if(i<0 || j<0) return 1e9;

//         if(dp[i][j]!=-1) return dp[i][j];
//         int left=grid[i][j]+f(i,j-1,grid,dp);
//         int up=grid[i][j]+f(i-1,j,grid,dp);

//         return dp[i][j]=min(left,up);

//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m= grid.size(); //row 
//         int n=grid[0].size();  //col
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return f(m-1,n-1,grid,dp);
//     }
// };






//recursive  -->>TLE
//  int f(int i, int j ,vector<vector<int>>& grid){
//         if(i==0 && j==0) return grid[i][j];
//         if(i<0 || j<0) return 1e9;

//         int left=grid[i][j]+f(i,j-1,grid);
//         int up=grid[i][j]+f(i-1,j,grid);

//         return min(left,up);

//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m= grid.size(); //row 
//         int n=grid[0].size();  //col

//         return f(m-1,n-1,grid);
//     }