class Solution 
{
public:
    Solution()
        :MaxNum_(1000001),
        cache_(MaxNum_,0)
    {
        for (uint64_t i = 2; i < MaxNum_; i++)
        {
            if (0 != cache_[i])
                continue;
            for (uint64_t j = i; j < MaxNum_; j += i)
            {
                if (0 == cache_[j])
                {
                    cache_[j] = i;
                }
            }
        }
    }
    int splitArray(vector<int>& nums) 
    {
        int cnt = nums.size();
        //分解数组长度
        vector<int> dp(cnt + 1, 0);
        //新增一个素数，最小长度
        vector<int> dp2(MaxNum_, cnt);

        for (int i = 1; i <= cnt;i++)
        {
            auto value = dp[i - 1] + 1;
            dp[i] = value;
            int num = nums[i - 1];
            
            while (num > 1)
            {
                int factor = cache_[num];
                dp[i] = std::min(dp[i], dp2[factor]);
                //新增数，或更新为dp[i-1]+1
                dp2[factor] = std::min(dp2[factor], value);
                //分解因子
                num /= factor;
            }
        }
        return dp.back();
    }
private:
    const uint64_t MaxNum_;
    std::vector<uint64_t> cache_;
};
