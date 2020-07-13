class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size(), 0);
        int min = prices.front();
        int max = dp.front();
        for (int i = 1;i < prices.size();i++)
        {
            dp[i] = min > prices[i] ? 0 : prices[i] - min;
            min = std::min(min, prices[i]);
            max = std::max(max, dp[i]);
        }
        return max;
    }
};
