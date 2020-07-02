class Solution 
{
public:
    bool compareAndSwap(std::string& str1, std::string& str2)
    {
        auto numstr1 = str1 + str2;
        auto numstr2 = str2 + str1;
        long num1 = std::stol(numstr1);
        long num2 = std::stol(numstr2);
        if (num1 > num2)
        {
            str1.swap(str2);
            return true;
        }
        return false;
    }
    string minNumber(vector<int>& nums) 
    {
        vector<std::string> numsStr(nums.size());
        int size = 0;
        for (int i=0;i<nums.size();i++)
        {
            numsStr[i] = std::to_string(nums[i]);
            size += numsStr[i].size();
        }
        for (int i = 0;i < numsStr.size()-1;i++)
        {
            for (int j = i + 1;j > 0;j--)
            {
                if (!compareAndSwap( numsStr[j-1], numsStr[j]))
                    break;
            }
        }
        std::string rst;
        rst.resize(size+5);
        rst.clear();
        for (int i = 0;i < numsStr.size();i++)
        {
            rst += numsStr[i];
        }
        return rst;
    }
};
