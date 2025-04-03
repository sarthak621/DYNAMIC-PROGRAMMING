class Solution {
public:
    //TABULATION-->SPACE OPTIMIZATION --> T.C O(n) S.C O(1) 

    int rob(vector<int>& nums) {
        
        int n=nums.size();

        // vector<int>dp(n,-1);

        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2; //to handle the negative cases

            int notTake=0+prev;

            int curi=max(take,notTake);

            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};


// //TABULATION --> T.C O(n) S.C O(n) { storing vector}

//     int rob(vector<int>& nums) {
        
//         int n=nums.size();

//         vector<int>dp(n,-1);

//         dp[0]=nums[0];
//         int neg=0;

//         for(int i=1;i<n;i++){
//             int take=nums[i];
//             if(i>1) take+=dp[i-2]; //to handle the negative cases

//             int notTake=0+dp[i-1];

//             dp[i]=max(take,notTake);
//         }
//         return dp[n-1];
//     }


// //MEMOIZATION --> T.C O(n) S.C O(n)+O(n) {Recursion stack and storing vector}
//     int solveRub(vector<int>& nums,int index,vector<int>&dp){
//         if(index==0) return nums[index];

//         if(index<0) return 0;

//         if(dp[index]!=-1) return dp[index];

//         //in case of pick we have not to go to adjacent house
//         int pick=solveRub(nums,index-2,dp)+nums[index];

//         //not pick -> if we go to adjacent house we make sure that we wont add anything
//         int notPick=solveRub(nums,index-1,dp)+0;

//         return dp[index]=max(pick,notPick);
//     }

//     int rob(vector<int>& nums) {
        
//         int n=nums.size();

//         vector<int>dp(n+1,-1);

//         return solveRub(nums,n-1,dp);
//     }
// };





//recursive -> TLE

//  int solveRub(vector<int>& nums,int index){
//         if(index==0) return nums[index];

//         if(index<0) return 0;

//         //in case of pick we have not to go to adjacent house
//         int pick=solveRub(nums,index-2)+nums[index];

//         //not pick -> if we go to adjacent house we make sure that we wont add anything
//         int notPick=solveRub(nums,index-1)+0;

//         return max(pick,notPick);
//     }

//     int rob(vector<int>& nums) {
        
//         int n=nums.size();

//         return solveRub(nums,n-1);
//     }