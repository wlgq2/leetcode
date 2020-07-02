class Solution 
{
public:
    TreeNode* findNode(vector<int>& preorder, vector<int>& inorder,int index,int start,int end)
    {
        if (start >= end)
            return NULL;
        auto root = new TreeNode(preorder[index]);
        for (int i = start;i < end;i++)
        {
            if (inorder[i] == preorder[index])
            {
                root->left = findNode(preorder, inorder, index + 1, start, i);
                root->right = findNode(preorder, inorder, i + index + 1 - start, i + 1, end);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return findNode(preorder, inorder, 0, 0,preorder.size());
    }
};
