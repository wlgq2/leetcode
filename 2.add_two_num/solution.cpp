class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto it1 = l1;
        auto it2 = l2;
        ListNode* rst = new ListNode(0);
        auto current = rst;
        int add = 0;
        while (it1 != NULL || it2 != NULL || add != 0)
        {
            auto num1 = it1 == NULL ? 0 : it1->val;
            auto num2 = it2 == NULL ? 0 : it2->val;
            int value = num1 + num2 +add;
            if (value < 10)
            {
                add = 0;
            }
            else
            {
                add = 1;
                value %= 10;
            }
      
            ListNode* node = new ListNode(value);
            current->next = node;
            current = node;
            it1 = it1==NULL? NULL:it1->next;
            it2 = it2==NULL? NULL:it2->next;
        }
        return rst->next;
    }
};
