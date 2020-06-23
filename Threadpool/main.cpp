#include "Threadpool.h"
#include <iostream>
using namespace wd;

/*
线程池设计：
1.线程池中存放任务队列(TaskQueue) 以及 子线程 (threads) 

2.有三个线程相关的类：
1）：一个是Thread虚基类，需要用工作线程类进行覆盖
2): 工作线程类WorkThread, 只需要重载run函数
3): 线程池类，每一个工作线程类调用的run函数都会最终调用线程池类中的处理任务函数，这样多个子线程都会不断等待并执行任务

3.退出机制
为了让线程池安全退出，需要在任务队列（TaskQueue）中，线程池中都存放一个 flag
任务队列中的flag: 可以判定线程池是否继续运行，若已经停止，那么唤醒所有条件等待的子线程并不再条件等待
线程池中的flag: 用来判断线程池是否继续运行，若已经停止，那么子线程将不再等待并获取任务。

4.任务类
子线程获取任务之后执行，任务类的书写方式跟工作线程类（WorkThread）相似

*/

class MyTask
:public Task
{
public:
    void process() override
    {
        int cnt = 3;
        while (cnt > 0)
        {
            srand(time(NULL));
            int val = rand() % 100;
            std::cout << pthread_self() << " is process the number:" << val << std::endl;
            sleep(1);
            cnt--;
        }
    }
};

int main()
{
    Threadpool threadpool(4, 10);
    threadpool.start();
    for (size_t i = 0; i < 3; i++)
    {
        threadpool.addTask(new MyTask());
    }
    sleep(1);
    threadpool.stop();
    return 0;
}