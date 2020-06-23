#include "Noncopyable.h"
#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>

class MyThread
:public wd::Thread
{
private:
    void run() override
    {
        while (1)
        {
            srand(time(NULL));
            std::cout << rand() % 100 << std::endl;
            sleep(1);
        }
    }
};


int main()
{
    std::unique_ptr<MyThread> p1(new MyThread());
    p1->start();
    p1->join();
    return 0;
}