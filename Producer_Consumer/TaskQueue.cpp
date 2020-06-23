#include "TaskQueue.h"
namespace wd
{
    TaskQueue::TaskQueue(size_t queSize)
        : _que(), _queSize(queSize), _mutexlock(), _fullAndWait(_mutexlock), _emptyAndWait(_mutexlock)
    {
    }

    TaskQueue::~TaskQueue()
    {
    }

    bool TaskQueue::full() const { return _que.size() == _queSize; }

    bool TaskQueue::empty() const { return _que.empty(); }

    void TaskQueue::push(int val)
    {
        {
            MutexLockGuard autolock(_mutexlock);
            while (full())
            {
                _fullAndWait.wait();
            }
            _que.push(val);
        }
        _emptyAndWait.notify();
    }

    int TaskQueue::pop()
    {
        int ret;
        {
            MutexLockGuard autolock(_mutexlock);
            while (empty())
            {
                _emptyAndWait.wait();
            }
            ret = _que.front();
            _que.pop();
        }
        _fullAndWait.notify();
        return ret;
    }
} // namespace wd