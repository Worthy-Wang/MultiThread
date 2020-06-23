#include "Noncopyable.h"
#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include <memory>
#include <functional>
using namespace wd;
using namespace std;

// class MyThread
// {
// private:
void run()
{
    while (1)
    {
        srand(time(NULL));
        std::cout << rand() % 100 << std::endl;
        sleep(1);
    }
}
// };

int main()
{
    unique_ptr<Thread> p(new Thread(run));
    p->start();
    p->join();
    return 0;
}