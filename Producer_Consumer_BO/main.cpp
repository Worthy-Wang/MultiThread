#include <iostream>
#include <memory>
#include "Thread.h"
#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"
using namespace wd;
using namespace std;

/*
基于对象的生产者消费者案例：
生产者与消费者各开启一个线程，并设计一个任务队列类，线程的同步与互斥都隐藏在任务队列的push 与 pop 函数里面，让程序更加简单明了

线程类的回调函数绑定的方法采用 bind 绑定 Consumer类 与 Producer类中的 run函数
*/


int main()
{
    TaskQueue taskQue(1);
    unique_ptr<Thread> p(new Thread(bind(&Producer::run, Producer(), ref(taskQue))));
    unique_ptr<Thread> c(new Thread(bind(&Consumer::run, Consumer(), ref(taskQue))));
    p->start();
    c->start();
    p->join();
    c->join();
    return 0;
}
