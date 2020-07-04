class Solution 
{
public:
    bool verifyPostorder(vector<int>& postorder, int start, int end)
    {
        if (start >= end)
            return true;
        int root = postorder[end];
        int index = end - 1;
        for (;index >= start;index--)
            if (postorder[index] < root)
                break;
        int less = index;
        while (less >= start)
            if (postorder[less--] >= root)
                return false;
        return verifyPostorder(postorder, start, index) && verifyPostorder(postorder, index + 1, end - 1);
    }
    bool verifyPostorder(vector<int>& postorder) 
    {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
};
