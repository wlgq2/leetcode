 class Solution 
 {
 public:
     vector<int> levelOrder(TreeNode* root) 
     {
         std::queue<TreeNode*> tree;
         if(NULL != root)
            tree.push(root);
         vector<int> rst(1000);
         rst.clear();
         while(!tree.empty())
         {
             auto current = tree.front();
             rst.push_back(current->val);
             tree.pop();
             if (current->left != NULL)
             {
                 tree.push(current->left);
             }
             if (current->right != NULL)
             {
                 tree.push(current->right);
             }
         }
         return rst;
     }
 };
