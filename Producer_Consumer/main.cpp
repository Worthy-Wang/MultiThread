#include <iostream>
#include <memory>
#include "Thread.h"
#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"
using namespace wd;
/*
面向对象的生产者消费者案例：
生产者与消费者各开启一个线程，并设计一个任务队列类，线程的同步与互斥都隐藏在任务队列的push 与 pop 函数里面，让程序更加简单明了
*/

int main()
{
    wd::TaskQueue taskQue(1);
    std::unique_ptr<Thread> p1(new Producer(taskQue));
    // std::unique_ptr<Thread> p2(new Producer(taskQue));
    std::unique_ptr<Thread> c1(new Consumer(taskQue));
    // std::unique_ptr<Thread> c2(new Consumer(taskQue));
    
    p1->start();
    // p2->start();
    c1->start();
    // c2->start();
    
    p1->join();
    // p2->join();
    c1->join();
    // c2->join();
    return 0;
}
