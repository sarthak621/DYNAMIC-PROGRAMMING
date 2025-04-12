class Solution {
public:
    
    //copied the code from dp37
    int f(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
        //base case
        if(ind==n){
            return 0;
        }

        if(cap==0) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy){
           profit=max(-prices[ind]+f(ind+1,0,cap,prices,n,dp), //take
                    0+ f(ind+1,1,cap,prices,n,dp) //not take
           );
        }


        //not buy-->sell
        else{
          profit=max(+prices[ind]+f(ind+1,1,cap-1,prices,n,dp), //take
                    0+ f(ind+1,0,cap,prices,n,dp) //not take
           );
        }

        return dp[ind][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
                ///as many time you want to buy you can buy or you want to sell you can sell

        int n=prices.size();
         
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        //Find the maximum profit you can achieve. You may complete at most two transactions.
        return f(0,1,k,prices,n,dp);  //index,buy
    }
};