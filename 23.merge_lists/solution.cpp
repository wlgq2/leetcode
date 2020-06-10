class Solution 
{
private:
    void addNode(int value)
    {
        auto it = cache_.find(value);
        if (it == cache_.end())
        {
            cache_[value] = 1;
        }
        else
        {
            it->second += 1;
        }
    }
    bool getNode(int& value)
    {
        auto it = cache_.begin();
        if (it == cache_.end())
        {
            return false;
        }
        it->second--;
        value = it->first;
        if (it->second == 0)
        {
            cache_.erase(it);
        }
        return true;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        cache_.clear();
        ListNode* rst(nullptr);
        
        for (auto& list : lists)
        {
            auto current = list;
            while (current != NULL)
            {
                addNode(current->val);
                current = current->next;
            }
        }
        int value;
        ListNode* current;
        while (getNode(value))
        {
            auto node = new ListNode(value);
            if (rst == NULL)
            {
                rst = node;
            }
            else
            {
                current->next = node;
            }
            current = node;
        }
        return rst;
    }
private:
    std::map<int, int> cache_;
};
