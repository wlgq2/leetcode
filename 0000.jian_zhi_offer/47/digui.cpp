class Solution1 
{
public:
    int maxValue(vector<vector<int>>& grid, int x, int y, int value)
    {
        value += grid[y][x];
        int value1 = value;
        int value2 = value;
        if (x < grid[0].size() - 1)
        {
            value1 = maxValue(grid, x + 1, y, value);
        }
        if (y < grid.size() - 1)
        {
            value2 = maxValue(grid, x, y + 1, value);
        }
        return value1 > value2 ? value1 : value2;
    }
    int maxValue(vector<vector<int>>& grid) 
    {
        return maxValue(grid, 0, 0, 0);
    }
};
