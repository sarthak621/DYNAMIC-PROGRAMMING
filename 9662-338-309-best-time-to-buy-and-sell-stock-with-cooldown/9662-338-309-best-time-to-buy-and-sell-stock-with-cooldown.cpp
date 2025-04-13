class Solution {
public:
//refer from buy and sell stock II and do minor change 
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//when you sell it make sure to go to ind+2 to buy
    
        
    //memoization
    int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
        //base case
        if(ind>=n){ //this cond. bcoz when we do ind+2 it can go to n+1
            return 0;
        }
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
           profit=max(-prices[ind]+f(ind+1,0,prices,n,dp), //take
                    0+ f(ind+1,1,prices,n,dp) //not take
           );
        }


        //not buy-->sell
        else{
          profit=max(+prices[ind]+f(ind+2,1,prices,n,dp), //take
                    0+ f(ind+1,0,prices,n,dp) //not take
           );
        }

        return dp[ind][buy]=profit;
    }
 
    int maxProfit(vector<int>& prices) {
        ///as many time you want to buy you can buy or you want to sell you can sell

        int n=prices.size();
         
         vector<vector<int>>dp(n,vector<int>(2,-1)); //either buy or not buy 0 or 1
        return f(0,1,prices,n,dp);  //index,buy


    }
    
};