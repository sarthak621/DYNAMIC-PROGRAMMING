class Solution {
public:
    
    //space optimized


    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n,m,s,p,dp);
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);


        prev[0]=true;

        // for(int i=1;i<=n;i++){
        //     dp[i][0]=false;
        // }

        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int left=1;left<=j;left++){
                if(p[left-1]!='*'){
                   flag=false;
                   break;
                } 
                
            }

            prev[j]=flag;
        }


        //copy the recc.
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

              if(s[i-1]==p[j-1] || p[j-1]=='?')  curr[j]=prev[j-1];
      
             else if(p[j-1]=='*'){
                   curr[j]=(prev[j]||curr[j-1]);
              }
      
              else curr[j]= false;
            }
            prev=curr;
        }

        return prev[m];

    }
};




    // //tabulation


    // bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();
        
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //     // return f(n,m,s,p,dp);

    //     dp[0][0]=true;

    //     for(int i=1;i<=n;i++){
    //         dp[i][0]=false;
    //     }

    //     for(int j=1;j<=m;j++){
    //         bool flag=true;
    //         for(int left=1;left<=j;left++){
    //             if(p[left-1]!='*'){
    //                flag=false;
    //                break;
    //             } 
                
    //         }

    //         dp[0][j]=flag;
    //     }


    //     //copy the recc.
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){

    //           if(s[i-1]==p[j-1] || p[j-1]=='?')  dp[i][j]=dp[i-1][j-1];
      
    //          else if(p[j-1]=='*'){
    //                dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
    //           }
      
    //           else dp[i][j]= false;
    //         }
    //     }

    //     return dp[n][m];

    // }








    // //memoization with index shifting
    // bool f(int i, int j ,string& s, string& p,vector<vector<int>>&dp){
    //     //base cases
        
    //     //if i and j both get exhausted
    //     if(i==0 && j==0) return true;

    //     //if j gets exhausted
    //     if(i>0 && j==0) return false;

    //     //if i gets exhausted and there is * left 
    //     if(i==0 && j>0){
    //         for(int left=1;left<=j;left++){
    //             if(p[left-1]!='*') return false;
    //         }
    //         return true;
    //     }
        
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     //R.R
        // if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);

        // if(p[j-1]=='*'){
        //     return dp[i][j]=(f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp));
        // }

        // else return false;
    // }

    // bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();
        
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,s,p,dp);
    // }








//  //memoization
//     bool f(int i, int j ,string& s, string& p,vector<vector<int>>&dp){
//     //     //base cases
        
//     //     //if i and j both get exhausted
//     //     if(i<0 && j<0) return true;

//     //     //if j gets exhausted
//     //     if(i>=0 && j<0) return false;

//     //     //if i gets exhausted and there is * left 
//     //     if(i<0 && j>=0){
//     //         for(int left=0;left<=j;left++){
//     //             if(p[left]!='*') return false;
//     //         }
//     //         return true;
//     //     }
        
//     //     if(dp[i][j]!=-1) return dp[i][j];

//     //     //R.R
//     //     if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);

//     //     if(p[j]=='*'){
//     //         return dp[i][j]=(f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp));
//     //     }

//     //     else return false;
//     // }

//     // bool isMatch(string s, string p) {
//     //     int n=s.size();
//     //     int m=p.size();
        
//     //     vector<vector<int>>dp(n,vector<int>(m+1,-1));
//     //     return f(n-1,m-1,s,p,dp);
//     // }

// rec
    // bool f(int i, int j ,string& s, string& p){
    //     //base cases
        
    //     //if i and j both get exhausted
    //     if(i<0 && j<0) return true;

    //     //if j gets exhausted
    //     if(i>=0 && j<0) return false;

    //     //if i gets exhausted and there is * left 
    //     if(i<0 && j>=0){
    //         for(int left=0;left<=j;left++){
    //             if(p[left]!='*') return false;
    //         }
    //         return true;
    //     }
        


    //     //R.R
    //     if(s[i]==p[j] || p[j]=='?') return f(i-1,j-1,s,p);

    //     if(p[j]=='*'){
    //         return (f(i-1,j,s,p)||f(i,j-1,s,p));
    //     }

    //     else return false;
    // }

    // bool isMatch(string s, string p) {
    //     int n=s.size();
    //     int m=p.size();

    //     return f(n-1,m-1,s,p);
    // }