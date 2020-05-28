class Solution 
{
public:
    void findLand(int col, int row, vector<vector<char>>& grid)
    {
        std::queue<int> rows;
        std::queue<int> cols;
        cols.push(col);
        rows.push(row);
        grid[col][row] = '0';
        while (!cols.empty())
        {
            auto rowN = rows.front();
            auto colN = cols.front();
            
            cols.pop();
            rows.pop();
            if ((rowN < grid.front().size() - 1) && grid[colN][rowN + 1] == '1')
            {
                cols.push(colN);
                rows.push(rowN + 1);
                grid[colN][rowN+1] = '0';
            }
            if ((colN < grid.size() - 1) && grid[colN+1][rowN] == '1')
            {
                cols.push(colN + 1);
                rows.push(rowN);
                grid[colN+1][rowN] = '0';
            }
            if ((colN > 0) && grid[colN - 1][rowN] == '1')
            {
                cols.push(colN - 1);
                rows.push(rowN);
                grid[colN - 1][rowN] = '0';
            }
            if ((rowN > 0) && grid[colN][rowN-1] == '1')
            {
                cols.push(colN);
                rows.push(rowN-1);
                grid[colN][rowN-1] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt = 0;
        for (auto i = 0; i < grid.size(); i++)
        {
            auto& v1 = grid[i];
            for (auto j = 0; j < v1.size(); j++)
            {
                if (v1[j] == '1')
                {
                    cnt++;
                    findLand(i, j, grid);
                }
            }
        }
        return cnt;
    }
};
