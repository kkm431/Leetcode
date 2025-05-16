class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size() - 1;
        int maxPrice= prices[n-1];

        int profit = 0;

        for(int i = n-2; i>=0; i--){
            maxPrice = max(prices[i], maxPrice);

            if(prices[i] < maxPrice){
                profit = max(-prices[i] + maxPrice, profit);
            }
        }

        return profit;
    }
};