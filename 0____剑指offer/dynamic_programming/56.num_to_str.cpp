class Solution 
{
public:
    int translateNum(int num) 
    {
        std::string str = std::to_string(num);
        vector<int> nums(str.size());
        nums.clear();
        for (auto ch : str)
        {
            nums.push_back(ch - 0x30);
        }
        vector<int> dp(str.size()+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1;i < nums.size();i++)
        {          
            int current = nums[i - 1] * 10 + nums[i];
            if (current < 26 && current>9)
            {
                dp[i + 1] = dp[i] + dp[i - 1];
            }
            else
            {
                dp[i + 1] = dp[i];
            }
        }
        return dp.back();
    }
};
