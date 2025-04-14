class Solution {
public:
   //copied the code from dp41 for printing LIS
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());  //change
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){   //change
                    // writing this line {1+dp[prev]>dp[i]} to avoid updating the same values in dp[ind]
                    dp[i]=1+dp[prev];
                    //update the hash 
                    hash[i]=prev;
                }
            }
            // maxi=max(maxi,dp[i]);
        }

        //ab hame sabka dp and hash table pata chal gaya hai
        
        //pehle largest dp[i] ko store karo
        
        int ans=-1;
        int lastIndex=-1;
        
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIndex=i;
            }
        }
        
        //ab hame largest dp[i] and uska index pata hai
        
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        
        while(hash[lastIndex]!= lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
         reverse(temp.begin(),temp.end());
         return temp;
    }
};