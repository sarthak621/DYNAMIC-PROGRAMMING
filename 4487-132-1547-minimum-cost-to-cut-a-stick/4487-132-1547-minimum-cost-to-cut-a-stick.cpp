class Solution {
public:
    //memoization
    int f(int i,int j, int n, vector<int>& cuts,vector<vector<int>>&dp){
        //base case
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        
        int mini=1e9;
        for(int ind=i;ind<=j;ind++){
           int cost=cuts[j+1]-cuts[i-1]
                + f(i,ind-1,n,cuts,dp)    //left guy
                + f(ind+1,j,n,cuts,dp);   //right guy
            
            mini=min(mini,cost);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int cutsSize=cuts.size(); //initial cuts array size

        //we are going to search b/w 0 to n
        cuts.push_back(n); //cuts wale array ke end me n daal diya
        cuts.insert(cuts.begin(),0);  //cuts wale array ke start me 0 dal diya
        // sort the cuts array
        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(cutsSize+1,vector<int>(cutsSize+1,-1));
        
        return f(1,cutsSize,n,cuts,dp);
        
    }
};



//recursion
    // int f(int i,int j, int n, vector<int>& cuts){
    //     //base case
    //     if(i>j) return 0;
        
    //     int mini=1e9;
    //     for(int ind=i;ind<=j;ind++){
    //        int cost=cuts[j+1]-cuts[i-1]
    //             + f(i,ind-1,n,cuts)    //left guy
    //             + f(ind+1,j,n,cuts);   //right guy
            
    //         mini=min(mini,cost);
    //     }

    //     return mini;
    // }
    // int minCost(int n, vector<int>& cuts) {
        
    //     int cutsSize=cuts.size(); //initial cuts array size

    //     //we are going to search b/w 0 to n
    //     cuts.push_back(n); //cuts wale array ke end me n daal diya
    //     cuts.insert(cuts.begin(),0);  //cuts wale array ke start me 0 dal diya
    //     // sort the cuts array
    //     sort(cuts.begin(),cuts.end());
        
    //     return f(1,cutsSize,n,cuts);
        
    // }