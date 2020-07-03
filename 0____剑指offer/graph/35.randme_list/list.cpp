class Solution 
{
public:
    Node* dfs(std::map<Node*, Node*>& isVisited, Node* node)
    {
        if (node != NULL)
        {
            Node* newNode;
            auto it = isVisited.find(node);
            if (it == isVisited.end())
            {
                newNode = new Node(node->val);
                isVisited[node] = newNode;
                newNode->next = dfs(isVisited, node->next);
                newNode->random = dfs(isVisited, node->random);
            }
            else
            {
                newNode = it->second;
            }
            return newNode;
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) 
    {
        std::map<Node*, Node*> isVisited;
        dfs(isVisited, head);
        return isVisited[head];
    }
};
