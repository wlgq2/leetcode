 class Solution 
 {
 public:
     vector<vector<int>> levelOrder(TreeNode* root) 
     {
         std::queue<TreeNode*> tree;
         if(NULL != root)
            tree.push(root);
         std::vector<vector<int>> rst;
         std::vector<int> temp;
         temp.resize(1000);
         temp.clear();
         auto last = root;
         auto newLast = last;
         while(!tree.empty())
         {
             auto current = tree.front();
             temp.push_back(current->val);
             tree.pop();
             if (current->left != NULL)
             {
                 tree.push(current->left);
                 newLast = current->left;
             }
             if (current->right != NULL)
             {
                 tree.push(current->right);
                 newLast = current->right;
             }
             if (current == last)
             {
                 last = newLast;
                 rst.push_back(temp);
                 temp.clear();
             }
         }
         return rst;
     }
 };
