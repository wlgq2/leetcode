class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> stack;
        for (auto& str : tokens)
        {
            if (str == "*")
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 *= num2;
                stack.push(num1);
            }
            else if (str == "/")
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num2 /= num1;
                stack.push(num2);
            }
            else if(str == "+")
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num1 += num2;
                stack.push(num1);
            }
            else if (str == "-")
            {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                num2 -= num1;
                stack.push(num2);
            }
            else
            {
                stack.push(std::stoi(str));
            }
        }
        return stack.top();
    }
};
