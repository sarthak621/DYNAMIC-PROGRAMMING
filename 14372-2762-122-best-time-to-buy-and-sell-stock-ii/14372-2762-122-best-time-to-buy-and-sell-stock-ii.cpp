class Solution {
public:
    //space opt.
    
    int maxProfit(vector<int>& prices) {
        ///as many time you want to buy you can buy or you want to sell you can sell

        int n=prices.size();
         
        //  vector<vector<int>>dp(n+1,vector<int>(2,0)); //either buy or not buy 0 or 1
        // return f(0,1,prices,n,dp);  //index,buy

        vector<int>ahead(2,0);
        vector<int>curr(2,0);


        //base case
        ahead[0]=ahead[1]=0;
        
        // int profit=0;
        //for loops

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
               int profit=0;
               if(buy){
                  profit=max(-prices[ind]+ahead[0], //take
                           0+ ahead[1] //not take
                  );
               }
       
       
               //not buy-->sell
               else{
                 profit=max(+prices[ind]+ahead[1], //take
                           0+ ahead[0] //not take
                  );
               }
       
                curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[1];


    }
};





// //tabulation
    
//     int maxProfit(vector<int>& prices) {
//         ///as many time you want to buy you can buy or you want to sell you can sell

//         int n=prices.size();
         
//          vector<vector<int>>dp(n+1,vector<int>(2,0)); //either buy or not buy 0 or 1
//         // return f(0,1,prices,n,dp);  //index,buy

//         //base case
//         dp[n][0]=dp[n][1]=0;
        
//         // int profit=0;
//         //for loops

//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                int profit=0;
//                if(buy){
//                   profit=max(-prices[ind]+dp[ind+1][0], //take
//                            0+ dp[ind+1][1] //not take
//                   );
//                }
       
       
//                //not buy-->sell
//                else{
//                  profit=max(+prices[ind]+dp[ind+1][1], //take
//                            0+ dp[ind+1][0] //not take
//                   );
//                }
       
//                 dp[ind][buy]=profit;
//             }
//         }

//         return dp[0][1];


//     }

    // //memoization
    // int f(int ind,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
    //     //base case
    //     if(ind==n){
    //         return 0;
    //     }
        
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit=0;
    //     if(buy){
    //        profit=max(-prices[ind]+f(ind+1,0,prices,n,dp), //take
    //                 0+ f(ind+1,1,prices,n,dp) //not take
    //        );
    //     }


    //     //not buy-->sell
    //     else{
    //       profit=max(+prices[ind]+f(ind+1,1,prices,n,dp), //take
    //                 0+ f(ind+1,0,prices,n,dp) //not take
    //        );
    //     }

    //     return dp[ind][buy]=profit;
    // }
 
    // int maxProfit(vector<int>& prices) {
    //     ///as many time you want to buy you can buy or you want to sell you can sell

    //     int n=prices.size();
         
    //      vector<vector<int>>dp(n,vector<int>(2,-1)); //either buy or not buy 0 or 1
    //     return f(0,1,prices,n,dp);  //index,buy


    // }








//recursrion

    // int f(int ind,int buy,vector<int>& prices,int n){
    //     //base case
    //     if(ind==n){
    //         return 0;
    //     }
        
    //     int profit=0;
    //     if(buy){
    //        profit=max(-prices[ind]+f(ind+1,0,prices,n), //take
    //                 0+ f(ind+1,1,prices,n) //not take
    //        );
    //     }


    //     //not buy-->sell
    //     else{
    //       profit=max(+prices[ind]+f(ind+1,1,prices,n), //take
    //                 0+ f(ind+1,0,prices,n) //not take
    //        );
    //     }

    //     return profit;
    // }
 
    // int maxProfit(vector<int>& prices) {
    //     ///as many time you want to buy you can buy or you want to sell you can sell

    //     int n=prices.size();

    //     return f(0,1,prices,n);  //index,buy


    // }