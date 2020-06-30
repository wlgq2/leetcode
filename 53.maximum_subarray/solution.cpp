class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        std::vector<int> dp(nums.size());
        dp[0] = nums.front();
        for (int i = 1;i < nums.size();i++)
        {
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
        }
        int max = dp.front();
        for (auto i = 1;i < dp.size();i++)
        {
            if (dp[i] > max)
            {
                max = dp[i];
            }
        }
        return max;
    }
};
