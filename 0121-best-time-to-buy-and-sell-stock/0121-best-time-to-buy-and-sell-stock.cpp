class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if (prices.size() < 2)
            return 0;
        int maxPrice= prices[n-1];

        int profit = 0;

        for(int i = n-2; i>=0; i--){

            

            if(prices[i] < maxPrice){
                profit = max(maxPrice - prices[i], profit);
            }
            else{
                maxPrice = max(prices[i], maxPrice);
            }
        }

        return profit;
    }
};