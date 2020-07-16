
class Solution 
{
public:
    int sort(vector<int>& nums, vector<int>& out,int start, int end)
    {
        int rst = 0;
        int mid = (start + end) / 2;
        if (start >= end - 1)
        {
            out.push_back(nums[start]);
            return rst;
        }
        std::vector<int> left(mid-start);
        left.clear();
        rst += sort(nums, left,start, mid);
        std::vector<int> right(end - mid);
        right.clear();
        rst += sort(nums, right, mid, end);
        int leftIndex = 0;
        int rightIndex = 0;
        while (true)
        {
            bool pushLeft = true;
            if (leftIndex>=left.size() && rightIndex >= right.size())
                break;
            else if (leftIndex >= left.size())
                pushLeft = false;
            else if (rightIndex >= right.size())
                pushLeft = true;
            else
                pushLeft = right[rightIndex] >= left[leftIndex];
            if (pushLeft)
                out.push_back(left[leftIndex++]);
            else
            {
                if(leftIndex<left.size() && right[rightIndex] != left[leftIndex])
                    rst += left.size()-leftIndex;
                out.push_back(right[rightIndex++]);
            }
        }
        return rst;
    }
    int reversePairs(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        std::vector<int> out(nums.size());
        out.clear();
        return sort(nums, out, 0, nums.size());
    }
};
