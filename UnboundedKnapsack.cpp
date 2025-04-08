

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
   //space opt
   
   vector<int>prev(w+1,0);
      vector<int>curr(w+1,0);

   
   //base cases
   for(int wt=0;wt<=w;wt++){
       prev[wt]=(wt/weight[0])*profit[0];
   }

   //for loops 
   	for(int i=1;i<n;i++){
		for(int Wt=0;Wt<=w;Wt++){
			int notPick= 0+prev[Wt];

            int pick=-1e9;
        
            if(weight[i]<=Wt){
        	  pick=profit[i]+curr[Wt-weight[i]];
            }
        
             curr[Wt]=max(pick,notPick);
		}
		prev=curr;
	}

    return prev[w];

    
}


// //tabulation
// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
   
//    vector<vector<int>>dp(n,vector<int>(w+1,0));
// //    return f(n-1,w,profit,weight,dp);
   
//    //base cases
//    for(int wt=0;wt<=w;wt++){
//        dp[0][wt]=(wt/weight[0])*profit[0];
//    }

//    //for loops 
//    	for(int i=1;i<n;i++){
// 		for(int Wt=0;Wt<=w;Wt++){
// 			int notPick= 0+dp[i-1][Wt];

//             int pick=-1e9;
        
//             if(weight[i]<=Wt){
//         	  pick=profit[i]+dp[i][Wt-weight[i]];
//             }
        
//              dp[i][Wt]=max(pick,notPick);
// 		}
		
// 	}

//     return dp[n-1][w];

    
// }





// //memoization
// int f(int n, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
//     //base cases
//    if(n==0){
//        if(weight[n]<=w){
//            return (w/weight[0])*profit[0];
//        }
//        return 0;
//    }
    
//     if(dp[n][w]!=-1) return dp[n][w];
//     int notPick=f(n-1,w,profit,weight,dp);
//     int pick=-1e9;
//     if(weight[n]<=w) pick=profit[n]+f(n,w-weight[n],profit,weight,dp);

//     return dp[n][w]=max(pick,notPick);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
   
//    vector<vector<int>>dp(n,vector<int>(w+1,-1));
//    return f(n-1,w,profit,weight,dp);

    
// }





//recursion
// int f(int n, int w, vector<int> &profit, vector<int> &weight){
//     //base cases
//    if(n==0){
//        if(weight[n]<=w){
//            return (w/weight[0])*profit[0];
//        }
//        return 0;
//    }

//     int notPick=f(n-1,w,profit,weight);
//     int pick=-1e9;
//     if(weight[n]<=w) pick=profit[n]+f(n,w-weight[n],profit,weight);

//     return max(pick,notPick);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
   

//    return f(n-1,w,profit,weight);
// }




