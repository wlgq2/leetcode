class Solution 
{
public:
    using TicketsType = std::map < std::string, std::shared_ptr<std::map<std::string, int>>>;
    void addTickets(TicketsType& ticketMap, vector<vector<string>>& tickets)
    {
        for (auto& ticket : tickets)
        {
            auto it = ticketMap.find(ticket[0]);
            if (it == ticketMap.end())
            {
                auto ptr = std::make_shared<std::map<std::string, int>>();
                ticketMap[ticket[0]] = ptr;
                (*ptr)[ticket[1]] = 1;
            }
            else
            {
                auto itt = it->second->find(ticket[1]);
                if (itt == it->second->end())
                {
                    (*(it->second))[ticket[1]] = 1;
                }
                else
                {
                    itt->second++;
                }
            }
        }
    }
    bool find(vector<string>& out, TicketsType& tickets, const std::string& current,int size)
    {
        out.push_back(current);
        if (out.size() == size)
        {
            return true;
        }
        auto it = tickets.find(current);
        if (it != tickets.end())
        {
            auto tickList = it->second;
            for (auto itt = tickList->begin();itt != tickList->end();itt++)
            {
                if (itt->second > 0)
                {
                    itt->second--;
                    auto rst = find(out, tickets, itt->first, size);
                    if (rst)
                        return true;
                    itt->second++;
                }
                
            }
        }
        out.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        int size = tickets.size()+1;
        TicketsType ticketMap;
        addTickets(ticketMap, tickets);
        vector<string> rst(size);
        rst.clear();
        std::string start("JFK");
        find(rst, ticketMap, start, size);
        return rst;
    }
};
