class Solution {
public:
    
    //space optimization
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();

        // vector<vector<int>>dp(n,vector<int>(n,-1)); //we have to create a  dp array of nXn
        vector<int>front(n,0);

        //base case
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for( int j=i;j>=0;j--){
                int down= triangle[i][j]+front[j];
                int up=triangle[i][j]+front[j+1];

                curr[j]=min(down,up);
            }
            front=curr;
        }
        return front[0];
    }
};



// // tablulation
    // int minimumTotal(vector<vector<int>>& triangle) {
        
    //     int n=triangle.size();

    //     vector<vector<int>>dp(n,vector<int>(n,-1)); //we have to create a  dp array of nXn

    //     //base case
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=triangle[n-1][j];
    //     }

    //     for(int i=n-2;i>=0;i--){
    //         for( int j=i;j>=0;j--){
    //             int down= triangle[i][j]+dp[i+1][j];
    //             int up=triangle[i][j]+dp[i+1][j+1];

    //             dp[i][j]=min(down,up);
    //         }
    //     }
    //     return dp[0][0];
    // }


// // memoization

// int f(int i,int j,vector<vector<int>>& triangle,int m ,int n,vector<vector<int>>&dp ){
//         if(i==m-1) return triangle[m-1][j];
        
//         if(dp[i][j]!=-1) return dp[i][j];

//         int down= triangle[i][j]+f(i+1,j,triangle,m,n,dp);
//         int diagonal=triangle[i][j]+f(i+1,j+1,triangle,m,n,dp);

//         return dp[i][j]=min(down, diagonal);

//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         int row=triangle.size();
//         int col=triangle[0].size();

//         vector<vector<int>>dp(row,vector<int>(row,-1)); //we have to create a  dp array of nXn

//         return f(0,0,triangle,row,col,dp);
//     }



// //recursion
//   int f(int i,int j,vector<vector<int>>& triangle,int m ,int n ){
//         if(i==m-1) return triangle[m-1][j];

//         int down= triangle[i][j]+f(i+1,j,triangle,m,n);
//         int diagonal=triangle[i][j]+f(i+1,j+1,triangle,m,n);

//         return min(down, diagonal);

//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         int row=triangle.size();
//         int col=triangle[0].size();

//         return f(0,0,triangle,row,col);
//     }