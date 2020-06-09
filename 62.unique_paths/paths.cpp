class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (n <= 0 || m <= 0)
        {
            return 0;
        }
        cache_.clear();
        cache_.resize(m);
        for (int i = 0;i < cache_.size();i++)
        {
            auto& line = cache_[i];
            line.resize(n);
            if (i == 0)
            {
                for (int j = 0;j < line.size();j++)
                {
                    line[j] = 1;
                }
            }
            else
            {
                line[0] = 1;
            }
        }
        for (int i = 1;i < m;i++)
        {
            for (int j = 1;j < n;j++)
            {
                cache_[i][j] = cache_[i][j - 1] + cache_[i - 1][j];
            }
        }
        return cache_[m - 1][n - 1];
    }
private:
    std::vector<std::vector<int>> cache_;

};
