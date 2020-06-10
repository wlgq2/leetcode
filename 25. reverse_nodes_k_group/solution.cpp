class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* rst = NULL;
        ListNode* node = head;
        
        ListNode* preEnd = NULL;
        ListNode* currentStart = NULL;
        while (node!= NULL)
        {
            ListNode* pre = NULL;
            currentStart = node;
            for (int i = 0;i < k;i++)
            {
                if (node == NULL)
                {
                    auto current2 = pre;
                    pre = NULL;
                    while (current2 != NULL)
                    {
                        auto temp = current2;
                        current2 = current2->next;
                        temp->next = pre;
                        pre = temp;
                    }
                    pre = currentStart;
                    break;
                }
                auto current = node;
                node = node->next;
                current->next = pre;
                pre = current;
            }
            if (rst == NULL)
            {
                rst = pre;
            }
            if (preEnd != NULL)
            {
                preEnd->next = pre;
            }
            preEnd = currentStart;
        }
        return rst;
    }
};
