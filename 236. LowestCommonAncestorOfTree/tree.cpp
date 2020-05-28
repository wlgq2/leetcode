class Solution 
{
    bool getPath(TreeNode* root, TreeNode* p,std::vector<TreeNode*>& path, int cnt)
    {
        if (!root)
            return false;
        if (cnt >= path.size())
            path.resize(cnt * 2 + 1);
        path[cnt] = root;
        if (root == p)
        {
            return true;
        }
        if (getPath(root->left, p,  path,cnt + 1 ))
            return true;
        return getPath(root->right, p, path, cnt + 1);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<TreeNode*> path1;
        std::vector<TreeNode*> path2;
        getPath(root, p, path1, 0);
        getPath(root, q, path2, 0);
        auto it2 = path2.begin();
        TreeNode* rst = *it2;
        for (auto it1 = path1.begin(); it1 != path1.end(); it1++)
        {
            if (*it1 == *it2)
            {
                rst = *it2;
            }
            else
            {
                break;
            }
            if (++it2 == path2.end())
            {
                break;
            }
        }
        return rst;
    }
};
