class Solution 
{
public:
    bool findSafe(vector<vector<int>>& graph, int N, std::vector<int8_t>& status)
    {
        if (status[N] == 2)
            return true;
        if (status[N] == -1)
            return false;
        if (status[N] == 1)
        {
            return false;
        }
        status[N] = 1;
        for (auto point : graph[N])
        {
            if (!findSafe(graph, point, status))
            {
                status[N] = -1;
                return false;
            }
        }
        status[N] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        std::vector<int> rst(graph.size());
        rst.clear();
        std::vector<int8_t> status(graph.size(), 0);
        for (int i = 0;i < graph.size();i++)
        {
            if (findSafe(graph, i, status))
            {
                rst.push_back(i);
            }
        }
        return rst;
    }
};
