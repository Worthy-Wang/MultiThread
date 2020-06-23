#include "Threadpool.h"
#include <iostream>
#include <functional>
using namespace wd;
using namespace std;

/*
基于对象的线程池设计：
Task 本质是一个 void() 型的函数
*/

class MyTask
{
public:
    MyTask(int cnt)
    :cnt(cnt)
    {}

    void process()
    {
        while (cnt > 0)
        {
            std::cout << "cnt = " << cnt << std::endl;
            srand(time(NULL));
            int val = rand() % 100;
            std::cout << pthread_self() << " is process the number:" << val << std::endl;
            cnt--;
            sleep(1);
        }
    }
private:
    int cnt;
};

int main()
{
    Threadpool threadpool(4, 10);
    threadpool.start();
    for (size_t i = 0; i < 3; i++)
    {
        cout << "i=" << i << endl;
        MyTask task(3);
        threadpool.addTask(std::bind(&MyTask::process, task));
    }
    sleep(1);
    threadpool.stop();
    return 0;
}