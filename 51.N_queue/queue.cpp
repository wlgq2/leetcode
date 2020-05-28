class Solution {
public:
    bool isEffective(int col, int row)
    {
        for (int i = 0;i < col;i++)
        {
            if (rst_[i] == row || abs(i - col) == abs(rst_[i] - row))
                return false;
        }
        return true;
    }
    void addSolve(bool turn)
    {
        rstStr_.resize(rstStr_.size() + 1);
        auto& rst = rstStr_.back();
        rst.resize(length_);
        for (auto i = 0;i < rst_.size();i++)
        {
            rst[i].resize(length_);
            rst[i].clear();
            for (auto j = 0;j < length_;j++)
            {
                if (turn)
                {
                    if (length_ - j-1 == rst_[i])
                        rst[i].push_back('Q');
                    else
                        rst[i].push_back('.');
                }
                else
                {
                    if (j == rst_[i])
                        rst[i].push_back('Q');
                    else
                        rst[i].push_back('.');
                }
            }
        }

    }
    void solve(int col)
    {
        if (col == length_)
        {
            addSolve(false);
            if (index_ < length_ >> 1)
            {
                addSolve(true);
            }
            return;
        }

        for (int i = 0;i < length_;i++)
        {
            if (isEffective(col, i))
            {
                rst_[col] = i;
                solve(col + 1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        length_ = n;
        rst_.resize(n);
        rstStr_.clear();

        auto len = length_ >> 1;
        if (length_ % 2 == 1)
        {
            len++;
        }
        for (index_ = 0;index_ < len;index_++)
        {

            if (isEffective(0, index_))
            {
                rst_[0] = index_;
                if(length_>0)
                    solve(1);
            }
        }
        return std::move(rstStr_);
    }
private:
    int length_;
    std::vector<int> rst_;
    vector<vector<string>> rstStr_;
    int index_;
};
