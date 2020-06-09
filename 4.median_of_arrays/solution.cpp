class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        auto size = nums1.size() + nums2.size();
        std::vector<int> rst(size);
        rst.clear();
        int i = 0;
        int j = 0;
        int mid = size >> 1;
        while(i < nums1.size() && j < nums2.size() && rst.size()<mid+2)
        {
            int num1 = nums1[i];
            int num2 = nums2[j];
            if (num1 < num2)
            {
                rst.push_back(num1);
                i++;
            }
            else
            {
                rst.push_back(num2);
                j++;
            }
        }
        while (i < nums1.size() && rst.size() < mid + 2)
        {
            rst.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size() && rst.size() < mid + 2)
        {
            rst.push_back(nums2[j]);
            j++;
        }
        
        if (size % 2 == 1)
        {
            return rst[mid];
        }
        double midNum = rst[mid-1]+ rst[mid ];
        return midNum / 2;
    }
};
