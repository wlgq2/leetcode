class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int num;
        int cnt = 0;
        for (int i = 0;i < nums.size();i++)
        {
            if (cnt == 0)
            {
                num = nums[i];
                cnt++;
            }
            else
            {
                cnt += (num == nums[i]) ? 1 : -1;
            }
        }
        return num;
    }
};
