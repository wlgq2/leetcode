class Solution 
{
public:
    Node* treeToDoublyList(Node* node, Node*& current,Node*& head)
    {
        if (node == NULL)
            return NULL;
        auto rst = treeToDoublyList(node->left,current,head);
        std::cout << node->val << std::endl;;
        if (head == NULL && node->left == NULL)
        {
            head = node;
            current = head;
        }
        else
        {
            current->right = node;
            node->left = current;
            current = node;
        }
        treeToDoublyList(node->right,current, head);
        return node;
    }
    Node* treeToDoublyList(Node* root) 
    {
        Node* head(NULL);
        Node* current(NULL);
        treeToDoublyList(root, current,head);
        if (current != NULL)
        {
            current->right = head;
            head->left = current;
        }
        return head;
    }
};
