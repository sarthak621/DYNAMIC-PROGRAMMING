class Solution {
public:

    // space optimization

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size(); //row
        int n=matrix[0].size(); //col

        vector<int>prev(n,0);
        vector<int>curr(m,0);

        //A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 

        //since it can start and end from any point.. so, we can find ans from any cell of the last row

        //base case
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+prev[j];

                int leftD=1e9,rightD=1e9;
                if(j-1>=0)  leftD=matrix[i][j]+prev[j-1]; //left diagonal
                if(j+1<n) rightD=matrix[i][j]+prev[j+1];     //right diagonal

                curr[j]=min(up,min(leftD,rightD));
            }
            prev=curr;
        }


        int mini=1e9;

        for(int j=0;j<n;j++){
            mini= min(mini,prev[j]);
        }

       return mini;
    }
};







// // tabulation

//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int m=matrix.size(); //row
//         int n=matrix[0].size(); //col

//         vector<vector<int>>dp(m,vector<int>(n,-1));

//         //A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 

//         //since it can start and end from any point.. so, we can find ans from any cell of the last row

//         //base case
//         for(int j=0;j<n;j++){
//             dp[0][j]=matrix[0][j];
//         }

//         for(int i=1;i<m;i++){
//             for(int j=0;j<n;j++){
//                 int up=matrix[i][j]+dp[i-1][j];

//                 int leftD=1e9,rightD=1e9;
//                 if(j-1>=0)  leftD=matrix[i][j]+dp[i-1][j-1]; //left diagonal
//                 if(j+1<n) rightD=matrix[i][j]+dp[i-1][j+1];     //right diagonal

//                 dp[i][j]=min(up,min(leftD,rightD));
//             }
//         }


//         int mini=1e9;

//         for(int j=0;j<n;j++){
//             mini= min(mini,dp[m-1][j]);
//         }

//        return mini;
//     }
// };




// //memoizATION-->T.L.E
//     int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
//         //base cases

//         //out of bound
//         if(j<0 || j>=matrix.size()) return 1e9;

//         if(i==0) return matrix[0][j];

//         if(dp[i][j]!=-1) return dp[i][j];

//         //r.r
//         int up=matrix[i][j]+f(i-1,j,matrix,dp);
//         int leftD=matrix[i][j]+f(i-1,j-1,matrix,dp); //left diagonal
//         int rightD=matrix[i][j]+f(i-1,j+1,matrix,dp);     //right diagonal

//         return dp[i][j]=min(up,min(leftD,rightD));

//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int m=matrix.size(); //row
//         int n=matrix[0].size(); //col

//         vector<vector<int>>dp(m,vector<int>(n,-1));

//         //A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 

//         //since it can start and end from any point.. so, we can find ans from any cell of the last row
//         int mini=1e9;

//         for(int j=0;j<n;j++){
//             mini= min(mini,f(m-1,j,matrix,dp));
//         }

//        return mini;
//     }
// };


// //recusive-->> T.L.E 

//     int f(int i,int j,vector<vector<int>>& matrix){
//         //base cases

//         //out of bound
//         if(j<0 || j>=matrix.size()) return 1e9;

//         if(i==0) return matrix[0][j];

//         //r.r
//         int up=matrix[i][j]+f(i-1,j,matrix);
//         int leftD=matrix[i][j]+f(i-1,j-1,matrix); //left diagonal
//         int rightD=matrix[i][j]+f(i-1,j+1,matrix);     //right diagonal

//         return min(up,min(leftD,rightD));

//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int m=matrix.size(); //row
//         int n=matrix[0].size(); //col

//         //A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 

//         //since it can start and end from any point.. so, we can find ans from any cell of the last row
//         int mini=1e9;

//         for(int j=0;j<n;j++){
//             mini= min(mini,f(m-1,j,matrix));
//         }

//        return mini;
//     }
