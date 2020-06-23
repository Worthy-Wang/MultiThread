#pragma once
#include <pthread.h>
#include <iostream>
#include "Noncopyable.h"

/*
线程类（虚基类）：
调用start函数时，创建线程并调用静态threadFunc函数，在threadFunc函数中调用纯虚函数run，当有
派生类继承虚基类Thread的时候，只需要覆盖run函数即可创建线程运行run函数，非常方便。 
*/

namespace wd
{
    class Thread
        : Noncopyable
    {
    public:
        Thread();
        virtual ~Thread();
        void start();
        void join();

    private:
        pthread_t _pid;
        bool _isRunning;
        virtual void run() = 0;
        static void *threadFunc(void * arg);
    };

} // namespace wd
