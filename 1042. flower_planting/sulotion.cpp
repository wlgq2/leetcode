struct Graph
{
    Graph(int cnt)
        :PointCnt(cnt)
    {
        paths.resize(cnt);
    }
    void addPath(int from, int to)
    {
        paths[from].push_back(to);
    }
    void connect(int p1, int p2)
    {
        addPath(p1, p2);
        addPath(p2, p1);
    }
    int PointCnt;
    std::vector<std::list<int>> paths;
};

class Solution 
{
public:
    int getColor( Graph& graph,int other, int index, std::vector<int>& colors)
    {
        int rst;
        auto& paths = graph.paths[index];
        for (rst = 1;rst < 5;rst++)
        {
            if (rst == other)
                continue;
            bool vaild = true;
            for (auto it = paths.begin();it != paths.end();it++)
            {
                if (colors[*it] == rst)
                {
                    vaild = false;
                    break;
                }
            }
            if(vaild)
                break;
        }
        return rst;
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        Graph graph(N);
        for (auto& path : paths)
        {
            graph.connect(path[0] - 1, path[1] - 1);
        }
        vector<int> rst(N, 0);
        std::queue<int> cache;
        std::vector<uint8_t> visited(rst.size(), 0);
        for (int i = 0;i < rst.size();i++)
        {
            int index = i;
            if (rst[index] == 1)
                continue;
            while (true)
            {
                if (rst[index] == 1)
                    break;
                visited[index] = 1;
                if (rst[index] == 0)
                {
                    rst[index] = getColor(graph, -1, index, rst);
                }
                int color = rst[index];
                auto& paths = graph.paths[index];
                for (auto it = paths.begin();it != paths.end();it++)
                {
                    if (rst[*it] == 0)
                    {
                        rst[*it] = getColor(graph, color, *it, rst);
                    }
                    if (visited[*it] == 0)
                        cache.push(*it);
                }
                if (cache.empty())
                    break;
                index = cache.front();
                cache.pop();
            }
        }
        return rst;
    }
};
