class Solution {
public:


    //tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-1));

        //if the value of cell (0,0) is 1 then direct return the 0
        if(obstacleGrid[0][0]==1) return 0;

        dp[0][0]=1;

        for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1){
                   dp[i][j]=0;
                   continue;
                } 
                if(i==0 && j==0){
                    // dp[0][0]=0;
                    continue;
                }

                int left=0,up=0;

                if(j>0) left=dp[i][j-1];
                if(i>0) up=dp[i-1][j];

                dp[i][j]=left+up;
                
              }
        }

        return dp[row-1][col-1];
    }
};



////memoization
//     int f(int i ,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
//         //base case
        

//         if(i<0 || j<0 ) return 0;

//         //also additional case here 1 is considered as a obstacle
//         if(obstacleGrid[i][j]==1) return 0;

//         if(i==0 && j==0) return 1;

//         if(dp[i][j]!=-1) return dp[i][j];

//         int up=f(i-1,j,obstacleGrid,dp);
//         int left=f(i,j-1,obstacleGrid,dp);

//         return dp[i][j]=up+left; 
//     } 

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int row=obstacleGrid.size();
//         int col=obstacleGrid[0].size();

//         vector<vector<int>>dp(row,vector<int>(col,-1));

//         return f(row-1,col-1,obstacleGrid,dp);
//     }
// };



//recursive
// int f(int i ,int j,vector<vector<int>>& obstacleGrid){
//         //base case
        

//         if(i<0 || j<0 ) return 0;

//         //also additional case here 1 is considered as a obstacle
//         if(obstacleGrid[i][j]==1) return 0;

//         if(i==0 && j==0) return 1;

//         int up=f(i-1,j,obstacleGrid);
//         int left=f(i,j-1,obstacleGrid);

//         return up+left; 
//     } 

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
//         int row=obstacleGrid.size();
//         int col=obstacleGrid[0].size();

//         return f(row-1,col-1,obstacleGrid);
//     }