class Solution
{
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        std::vector<vector<int>> dp(grid.size());
        for (auto& x : dp)
        {
            x.resize(grid.back().size());
        }
        dp[0][0] = grid[0][0];
        for (int i = 1;i < grid.back().size();i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size();i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1;i < grid.size();i++)
        {
            for (int j = 1;j < grid.front().size();j++)
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp.back().back();
    }
};
