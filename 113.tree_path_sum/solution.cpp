class Solution
 {
 public:
     void dfs(TreeNode* node, int sum, int current, std::vector<int>& list)
     {
         if (node == NULL)
             return;
         current += node->val;
         list.push_back(node->val);
         if (node->left == NULL && node->right == NULL)
         {
             if (current == sum)
             {
                 cache.push_back(list);
             }
         }
         else
         {
             dfs(node->left, sum, current, list);
             dfs(node->right, sum, current, list);
         }
         list.pop_back();
     }
     vector<vector<int>> pathSum(TreeNode* root, int sum)
     {
         cache.clear();
         std::vector<int> list(100);
         list.clear();
         dfs(root, sum, 0, list);
         return cache;
     }
 private:
     std::vector<vector<int>> cache;
 };
