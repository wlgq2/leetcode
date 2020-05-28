struct StackNode
{
    StackNode(int v, StackNode* p)
        :value(v),
        pre(p)
    {

    }
    int value;
    StackNode* pre;
    int min;
};
class MinStack {
    public:
        MinStack() 
            :current_(nullptr)
        {

        }

        void push(int x) 
        {
            auto node = new StackNode(x,nullptr);
            if (nullptr == current_)
            {
                current_ = node;
                node->min = x;
            }
            else
            {
                node->pre = current_;
                node->min = node->value < current_->min? x : current_->min;
                current_ = node;
            }
        }

        void pop() 
        {
            auto temp = current_;
            current_ = current_->pre;
            delete temp;
        }

        int top() 
        {
            if (nullptr != current_)
            {
                return current_->value;
            }
            return 0;
        }

        int getMin() 
        {
            if (nullptr != current_)
                return current_->min;
            return 0;
        }
private :
    StackNode* current_;
};
