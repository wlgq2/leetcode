class Foo 
{
public:
    Foo() 
        :one_(false),
        second_(false)
    {

    }

    void first(function<void()> printFirst) 
    {
        unique_lock<mutex> lock(mutex_);
        printFirst();
        one_ = true;
        condition_.notify_all();
    }

    void second(function<void()> printSecond) 
    {
        unique_lock<mutex> lock(mutex_);
        condition_.wait(lock, [this]() { return one_; });
        printSecond();
        second_ = true;
        condition_.notify_all();
    }

    void third(function<void()> printThird) 
    {
        unique_lock<mutex> lock(mutex_);
        condition_.wait(lock, [this]() { return second_; });
        printThird();
    }
private:
    condition_variable condition_;
    mutex mutex_;
    bool one_;
    bool second_;
};
