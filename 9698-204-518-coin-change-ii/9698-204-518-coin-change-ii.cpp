class Solution {
public:

//referring from L.C 318 or dp[20]

    int change(int amount, vector<int>& coins) {
        unsigned long long n=coins.size();

        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<unsigned long long>prev(amount+1,0);
        vector<unsigned long long>curr(amount+1,0);

        
        //base cases
        for(unsigned long long target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=1;
            else prev[target]=0;
        }
        
        //for loops
        for(unsigned long long ind=1;ind<n;ind++){
            for(unsigned long long target=0;target<=amount;target++){
              //pick //not pick

              unsigned long long notPick=prev[target];
              unsigned long long pick=0; //int max
            //   if(target>=coins[ind]) pick=1+prev[target-coins[ind]];

            // using **prev** even when you're picking the current coin — this is not correct in an unbounded knapsack problem.
              if(target>=coins[ind]) pick=curr[target-coins[ind]];  


              curr[target]=pick+notPick;
            }
            prev=curr;
        }
        return prev[amount];
        // return (res >= 1e9) ? -1 : res;
    }
};