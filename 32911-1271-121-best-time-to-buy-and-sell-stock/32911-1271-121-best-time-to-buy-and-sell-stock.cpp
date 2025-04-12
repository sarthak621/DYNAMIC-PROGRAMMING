class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we have to maximize the profit

        //intution: if you are selling on ith day then you buy it on min. price from 0th to (i-1)th day

        int min_buy=prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++){
            int cost= prices[i]-min_buy;

            profit=max(profit,cost);

            min_buy=min(min_buy,prices[i]);
        }

        return profit;
    }
};