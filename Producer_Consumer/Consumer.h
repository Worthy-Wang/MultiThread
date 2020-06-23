#pragma once
#include "TaskQueue.h"
#include "Thread.h"
#include <iostream>
#include <unistd.h>

namespace wd
{
    class Consumer
        : public Thread
    {
    public:
        Consumer(TaskQueue& taskQue)
        :_taskQue(taskQue)
        {

        }

        void run() override
        {
            while (1)
            {
                int val = _taskQue.pop();
                std::cout << pthread_self() << " Consumer has consumed " << val << std::endl;
                sleep(2);
            }
        }

    private:
        TaskQueue& _taskQue;
    };
} // namespace wd