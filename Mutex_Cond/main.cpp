#include "Condition.h"
#include "MutexLock.h"
#include <iostream>
#include <unistd.h>
using namespace wd;
using namespace std;

MutexLock mutexlock;
Condition cond(mutexlock);

void* threadFunc(void* arg)
{
    cout << "in threadFunc" << endl;
    MutexLockGuard autolock(mutexlock);
    cout << "waiting" << endl;
    cond.wait();
    cout << "waiting over" << endl;
}

int main()
{
    pthread_t pth;
    pthread_create(&pth, NULL, threadFunc, NULL);
    sleep(3);
    cond.notify();
    pthread_join(pth, NULL);
    return 0;
}
