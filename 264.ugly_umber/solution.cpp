class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        std::vector<int> dp(n);
        dp[0] = 1;
        int index1=0, index2=0, index3 = 0;
        for (int i = 1;i < n;i++)
        {
            int num1 = dp[index1] * 2;
            int num2 = dp[index2] * 3;
            int num3 = dp[index3] * 5;
            dp[i] = std::min(std::min(num1, num2), num3);
            if (num1 == dp[i])
                index1++;//如果相等，则更新索引加1
            if (num2 == dp[i])
                index2++;
            if (num3 == dp[i])
                index3++;
        }
        return dp.back();
    }
};
