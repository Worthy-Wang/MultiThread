#pragma once
#include "Thread.h"

namespace wd
{
    class Threadpool;
    class WorkThread
    :public Thread
    {
    public:
        WorkThread(Threadpool& threadpool)
        :_threadpool(threadpool)
        {
        }

        void run() override;
    private:
        Threadpool& _threadpool;
    };
}