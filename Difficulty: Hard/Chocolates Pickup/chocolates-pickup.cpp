//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  //memoization
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        
        
        //base cases
        //out of bound cond.
        if(j1<0||j2<0||j1>=m||j2>=m){
            return -1e8;
        }
        
        //base case
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2]; 
        
        
        //R.R
        int maxi=-1e8;
        //explore all the paths of the robot 1 and robot2  simultaneously
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2){
                    value=grid[i][j1];
                }
                else{
                    value=grid[i][j1]+grid[i][j2];
                }
                value+=f(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                
                maxi=max(maxi,value);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // n rows, m cols 
        
        // dp[r][c][c]
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return f(0,0,m-1,n,m,grid,dp);
    }
};





// // recursive 
// int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid){
        
        
//         //base cases
//         //out of bound cond.
//         if(j1<0||j2<0||j1>=m||j2>=m){
//             return -1e8;
//         }
        
//         //base case
//         if(i==n-1){
//             if(j1==j2) return grid[i][j1];
//             else{
//                 return grid[i][j1]+grid[i][j2];
//             }
//         }
        
        
//         //R.R
//         int maxi=-1e8;
//         //explore all the paths of the robot 1 and robot2  simultaneously
//         for(int dj1=-1;dj1<=1;dj1++){
//             for(int dj2=-1;dj2<=1;dj2++){
//                 int value=0;
//                 if(j1==j2){
//                     value=grid[i][j1];
//                 }
//                 else{
//                     value=grid[i][j1]+grid[i][j2];
//                 }
//                 value+=f(i+1,j1+dj1,j2+dj2,n,m,grid);
                
//                 maxi=max(maxi,value);
//             }
//         }
        
//         return maxi;
//     }
    
//     int solve(int n, int m, vector<vector<int>>& grid) {
//         // code here
//         // n rows, m cols 
//         return f(0,0,m-1,n,m,grid);
//     }





















//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends