class Codec
{
public:
    string serialize(TreeNode* root) 
    {
        if (root == NULL)
            return "[]";
        std::list<TreeNode*> list;
        list.push_back(root);
        auto it = list.begin();
        while (it != list.end())
        {
            TreeNode* node = *it;
            if (node != NULL)
            {
                list.push_back(node->left);
                list.push_back(node->right);
            }
            it++;
        }
        while (list.back() == NULL)
        {
            list.pop_back();
        }
        string rst;
        rst.resize(list.size()*5);
        rst.clear();
        rst += "[";
        for (auto it = list.begin();it != list.end();it++)
        {
            if (*it != NULL)
            {
                rst += std::to_string((*it)->val);
                rst += ",";
            }
            else
                rst += "null,";
        }
        if (list.empty())
            rst.push_back(']');
        else
            rst.back() = ']';
        return rst;
    }

    void pushNode(std::list<TreeNode*>& queue, std::string& str)
    {
        if (str == "")
            return;
        if (str == "null")
            queue.push_back(NULL);
        else
        {
            TreeNode* node = new TreeNode(std::stol(str));
            queue.push_back(node);
        }
        str.clear();
    }
    TreeNode* deserialize(string data) 
    {
        TreeNode* rst(NULL);
        std::list<TreeNode*> list;
        std::string temp;
        for (int i = 1;i < data.size();i++)
        {
            if (data[i] == ',')
            {
                pushNode(list, temp);
                continue;
            }
            if (data[i] == ']')
            {
                pushNode(list, temp);
                break;
            }
            temp.push_back(data[i]);
        }
        auto it = list.begin();
        if (!list.empty())
        {
            rst = list.front();
            it++;
        }  
        while (!list.empty())
        {
            auto node = list.front();
            list.pop_front();
            if (NULL == node)
                continue;
            if (it != list.end())
            {
                node->left = *it;
                it++;
                if (it != list.end())
                {
                    node->right = *it;
                    it++;
                }
            }
        }
        return rst;
    }
};
