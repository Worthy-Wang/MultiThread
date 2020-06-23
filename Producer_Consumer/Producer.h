#pragma once
#include "TaskQueue.h"
#include "Thread.h"
#include <iostream>
#include <unistd.h>

namespace wd
{
    class Producer
        : public Thread
    {
    public:
        Producer(TaskQueue& taskQue)
        :_taskQue(taskQue)
        {

        }

        void run() override
        {
            while (1)
            {
                srand(time(NULL));
                int val = rand() % 100;
                std::cout << pthread_self() << " >>Producer has produced " << val << std::endl;
                _taskQue.push(val);
                sleep(1);
            }
        }

    private:
        TaskQueue& _taskQue;
    };
} // namespace wd