class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dp(s.size() + 1, 0);
        std::map<char, int> indexs;
        for (int i = 0;i < s.size();i++)
        {
            auto it = indexs.find(s[i]);
            dp[i + 1] = it == indexs.end() ? dp[i] + 1 : std::min(i - it->second, dp[i] + 1);
            indexs[s[i]] = i;
        }
        int max = dp.front();
        for (int i = 1;i < dp.size();i++)
            max = dp[i] > max ? dp[i] : max;
        return max;
    }
};
