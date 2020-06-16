class Solution 
{
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        vector<uint8_t> notTrustMen(N + 1, 0);
        vector<uint64_t> trustCnt(N + 1, 0);
        list<int> rstMen;
        for (auto& men : trust)
        {
            notTrustMen[men[0]] = 1;
            ++trustCnt[men[1]];
        }
        for (auto i = 1;i < N+1;i++)
        {
            if (trustCnt[i] == N - 1 && notTrustMen[i] == 0)
                return i;
        }
        return -1;
    }
};
