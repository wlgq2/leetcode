class Solution {
public:
    bool isValid(string s) 
    {
        std::stack<char> stack;
        for (auto ch : s)
        {
            switch (ch)
            {
            case '(':
            case '{':
            case '[':
                stack.push(ch);
                break;
            case ')':
                if (stack.empty())
                    return false;
                if (stack.top() != '(')
                    return false;
                stack.pop();
                break;
            case '}':
                if (stack.empty())
                    return false;
                if (stack.top() != '{')
                    return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty())
                    return false;
                if (stack.top() != '[')
                    return false;
                stack.pop();
                break;
            default:
                return false;
            }
        }
        return stack.empty();
    }
};
