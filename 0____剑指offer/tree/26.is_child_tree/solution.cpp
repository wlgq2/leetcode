class Solution 
{
public:
    bool isSub(TreeNode* A, TreeNode* B)
    {
        if (B == NULL)
            return true;
        if (A == NULL || A->val != B->val)
            return false;
        return isSub(A->left, B->left) && isSub(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (B == NULL || A == NULL)
            return false;
        return  isSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
