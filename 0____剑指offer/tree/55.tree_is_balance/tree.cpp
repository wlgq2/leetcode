class Solution 
{
public:
    bool isBalanced(TreeNode* node,int& legth)
    {
        if (node == NULL)
            return true;
        legth += 1;
        int left = legth;
        int right = legth;
        if (!isBalanced(node->left, left))
            return false;
        if (!isBalanced(node->right, right))
            return false;
        int max = std::max(left, right);
        int min = std::min(left, right);
        if (max - min > 1)
            return false;
        legth = max;
        return true;
    }
    bool isBalanced(TreeNode* root) 
    {
        int legth = 0;
        return isBalanced(root, legth);
    }
};
