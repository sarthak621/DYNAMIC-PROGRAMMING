class Solution {
public:

//referring the code of LCS and do minor changes

      int longestCommonSubsequence(string text1, string text2) {
           int n=text1.size();
        int m=text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        //base cases
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;

        // return f(n,m,text1,text2,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 int match=0,notMatch=0;
                if(text1[i-1]==text2[j-1])
                 match=1+dp[i-1][j-1];
        
                //not match
                else
                 notMatch=0+max(dp[i-1][j],dp[i][j-1]);
        
                dp[i][j]=max(match,notMatch);
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n=word1.size(); 
        int m=word2.size();

        int lcs=longestCommonSubsequence(word1,word2);

        int No_Of_Deletion=n-lcs;
        int No_Of_Insertion=m-lcs;

        int ans=No_Of_Deletion+No_Of_Insertion;
        return ans;
    }
};