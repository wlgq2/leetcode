class Solution 
{
public:
    void  haveNode(TreeNode* node, TreeNode* p,TreeNode* q,TreeNode*& out)
    {
        if (node == NULL || out != NULL)
            return;

        if ((node->val >= q->val && node->val <= p->val) ||
            (node->val <= q->val && node->val >= p->val))
        {
            out = node;
        }
        else if (node->val >= q->val && node->val >= p->val)
        {
            haveNode(node->left, p, q, out);
        }
        else if (node->val <= q->val && node->val <= p->val)
        {
            haveNode(node->right, p, q, out);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* node(NULL);
        haveNode(root, p, q,node);
        return node;
    }
};
