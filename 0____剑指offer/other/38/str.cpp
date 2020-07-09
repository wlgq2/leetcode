class Solution
{
public:
    void permutation(string& str, string& temp,vector<string>& strs)
    {
        auto index = temp.size();
        if (index == str.size())
        {
            strs.push_back(temp);
            return;
        }
        std::set<int> cache;
        for (int i = index;i <str.size(); i++)
        {
            auto ch = str[i];
            if (cache.find(ch) == cache.end())
            {
                cache.insert(ch);
                temp.push_back(ch);
                str[i] = str[index];
                str[index] = ch;
                permutation(str, temp, strs);
                str[index] = str[i];
                str[i] = ch;
                temp.pop_back();
            }
        }
    }
    vector<string> permutation(string s)
    {
        vector<string> rst;
        string temp;
        temp.resize(s.size());
        temp.clear();
        permutation(s, temp, rst);
        return rst;
    }
};
