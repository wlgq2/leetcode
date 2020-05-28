class MyCircularQueue {
public:
    MyCircularQueue(int k)
        :readIndex_(0),
        writeIndex_(0)
    {
        size_ = k + 1;
        data_ = new int[size_];
    }
    ~MyCircularQueue()
    {
        delete[] data_;
    }
    bool enQueue(int value) 
    {
        if (isFull())
            return false;
        data_[writeIndex_++] = value;
        if (writeIndex_ >= size_)
        {
            writeIndex_ = 0;
        }
        return true;
    }

    bool deQueue() 
    {
        if (isEmpty())
            return false;
        if (++readIndex_ >= size_)
        {
            readIndex_ = 0;
        }
        return true;
    }

    int Front() 
    {
        if (isEmpty())
            return -1;
        return data_[readIndex_];
    }

    int Rear() 
    {
        if (isEmpty())
            return -1;
        int index = writeIndex_ - 1;
        if (index < 0)
            index = size_ - 1;
        return data_[index];
    }

    bool isEmpty() 
    {
        return readIndex_ == writeIndex_;
    }

  
    bool isFull() 
    {
        if (writeIndex_ >= readIndex_)
            return writeIndex_ - readIndex_ == size_ -1;
        else
            return readIndex_ == writeIndex_ + 1;
    }
private:
    int* data_;
    uint64_t size_;
    int64_t readIndex_;
    int64_t writeIndex_;
};
