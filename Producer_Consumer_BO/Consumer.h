#pragma once
#include "TaskQueue.h"
#include "Thread.h"
#include <iostream>
#include <unistd.h>

namespace wd
{
    class Consumer
    {
    public:
        void run(TaskQueue& _taskQue)
        {
            while (1)
            {
                int val = _taskQue.pop();
                std::cout << pthread_self() << " Consumer has consumed " << val << std::endl;
                sleep(2);
            }
        }
    };
} // namespace wd