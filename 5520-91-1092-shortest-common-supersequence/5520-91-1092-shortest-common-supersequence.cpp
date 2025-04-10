class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        //code copied from the lcs dp[25]
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        //base cases
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;

        // return f(n,m,text1,text2,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 int match=0,notMatch=0;
                if(str1[i-1]==str2[j-1])
                 match=1+dp[i-1][j-1];
        
                //not match
                else
                 notMatch=0+max(dp[i-1][j],dp[i][j-1]);
        
                dp[i][j]=max(match,notMatch);
            }
        }
        
        
        int i=n;
        int j=m;
       string lcs="";
       //for printing
        while(i>0 && j>0){
           if(str1[i-1]==str2[j-1]){
            lcs.push_back(str1[i-1]);
            i--;
            j--;
           }

           else if(dp[i-1][j]>dp[i][j-1]){
                lcs.push_back(str1[i-1]);
               i--;
           }

           else{
               lcs.push_back(str2[j-1]);
               j--;
           }
        }

        // agar i and j me kuch remaining reh jaye to usko add kardo

        while(i>0){
                lcs.push_back(str1[i-1]);
               i--;
        }

        while(j>0){
            lcs.push_back(str2[j-1]);
             j--;
        }

        reverse(lcs.begin(),lcs.end());
        return lcs;
    }
};