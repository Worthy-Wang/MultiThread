#pragma once
#include "Condition.h"
#include "MutexLock.h"
#include <queue>

namespace wd
{
    class TaskQueue
    {
    public:
        TaskQueue(size_t queSize = 10);
        ~TaskQueue();
        bool full() const;
        bool empty() const;
        void push(int);
        int pop();

    private:
        std::queue<int> _que;
        size_t _queSize;
        MutexLock _mutexlock;
        Condition _fullAndWait;
        Condition _emptyAndWait;
    };


} // namespace wd