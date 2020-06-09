class Solution 
{
public:
    int minDistance(string&& word1, string&& word2) 
    {
        return minDistance(word1, word2);
    }
    int minDistance(string& word1, string& word2)
    {
        std::vector<std::vector<int>> dp(word1.size() + 1);
        for (int i = 0;i < dp.size();i++)
        {
            dp[i].resize(word2.size() + 1);
            if (i == 0)
            {
                for (int j = 0;j < dp[i].size();j++)
                {
                    dp[i][j] = j;
                }
            }
            else
            {
                dp[i][0] = i;
            }
        }
        for (int i = 1;i < word1.size()+1;i++)
        {
            for (int j = 1;j < word2.size() + 1;j++)
            {
                int value1 = dp[i][j - 1] + 1;
                int value2 = dp[i - 1][j] + 1;
                int value3 = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                {
                    value3 += 1;
                }
                dp[i][j] = std::min(std::min(value1, value2), value3);
            }
        }
        return dp.back().back();
    }
};
