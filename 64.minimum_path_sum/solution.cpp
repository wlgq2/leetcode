class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>> rst = grid;
        for (int i = 1;i < rst.size();i++)
        {
            rst[i][0] += rst[i - 1][0];
        }
        for (int i = 1;i < rst.front().size();i++)
        {
            rst.front()[i] += rst.front()[i - 1];
        }
        for (int i = 1;i < grid.size();i++)
        {
            for (int j = 1;j < grid[i].size();j++)
            {
                auto pre = rst[i - 1][j] > rst[i][j - 1] ? rst[i][j - 1] : rst[i - 1][j];
                rst[i][j] += pre;
            }
        }
        return rst.back().back();
    }
};
