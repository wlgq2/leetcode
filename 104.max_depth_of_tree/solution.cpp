 class Solution 
 {
 public:
     int getMaxDepth(TreeNode* root, int legth)
     {
         if (root == NULL)
             return legth;
         auto left = getMaxDepth(root->left, legth + 1);
         auto right = getMaxDepth(root->right, legth + 1);
         return left > right ? left : right;
     }
     int maxDepth(TreeNode* root) 
     {
         return getMaxDepth(root, 0);
     }
 };
