class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // We know prices has at least one so set default min
        int buyPrice = prices[0];
        int maxProfit = 0;
        
        // Iterate over the prices
        for (int atDay = 0; atDay < prices.size(); atDay++) {
            int profitAtDay = prices[atDay] - buyPrice;
            if (profitAtDay < 0) {
                buyPrice = prices[atDay];
            }
            if (profitAtDay >= maxProfit) {
                maxProfit = profitAtDay;
            }            
        }
        
        return maxProfit;
    }
};