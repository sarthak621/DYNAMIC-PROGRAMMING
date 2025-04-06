class Solution {
public:
      
      // taken code from lect 15 dp

     // space optimization
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here

        int n=arr.size();
        
        vector<bool>prev(sum+1,0);
        vector<bool>curr(sum+1,0);
        
        
        //base cases
        // for(int i=0;i<n;i++){
        //     dp[i][0]=true;
        // }
        
        // dp[0][arr[0]]=true;
        
        prev[0]=curr[0]=true;
        
        if(arr[0]<=sum) prev[arr[0]]=true;
        
        //form the nested loops
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                 //recursion
                 bool notTake=  prev[j];
                 
                 bool take= false;
                 
                 if(j>=arr[i]){
                     take= prev[j-arr[i]];
                 }
                 
                 curr[j]=notTake||take;
            }
            prev=curr;
        }
        
        return prev[sum];
    }


    bool canPartition(vector<int>& nums) {
        
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }

        if(totSum%2 !=0) return false;

        int target=totSum/2;

        return isSubsetSum(nums,target);

        
    }
};