struct Graph
{
    Graph(int cnt)
        :PointCnt(cnt)
    {
        edges.resize(cnt);
    }
    void addEdge(int from, int to)
    {
        edges[from].push_back(to);
    }
    void connect(int p1, int p2)
    {
        addEdge(p1, p2);
        addEdge(p2, p1);
    }
    int PointCnt;
    std::vector<std::list<int>> edges;
};
class Solution 
{
    void getCnt(Graph& graph, int index, vector<int>& childs,string& labels, vector<int>& rst)
    {
        int label = labels[index] - 'a';
        childs[label]++;
        rst[index] = 1;
        for (auto child : graph.edges[index])
        {
            vector<int> temp(26);
            getCnt(graph,  child, temp,labels, rst);
            rst[index] += temp[label];
            for (int i = 0;i < 26;i++)
            {
                childs[i] += temp[i];
            }
        }

    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> temp(n, 0);
        Graph graph(n);
        for (auto& edge : edges)
        {
            if (edge[1] != 0 && temp[edge[1]] == 0)
            {
                graph.addEdge(edge[0], edge[1]);
                temp[edge[1]] = 1;
            }
            else
            {
                graph.addEdge(edge[1], edge[0]);
                temp[edge[0]] = 1;
            }
        }
        vector<int> rst(n, 0);
        vector <int> childs(26);
        getCnt(graph, 0, childs,labels, rst);
        return rst;
    }
};
