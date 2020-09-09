#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <string>
using namespace std;

/*
线程局部存储(TLS):

*/

// static int a = 5;
static __thread int a = 5;


void* threadFunc(void* arg)
{
    cout << "子线程" << pthread_self() << " a地址:" << &a << endl;
}


int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, threadFunc, NULL);
    pthread_create(&p2, NULL, threadFunc, NULL);
    cout << "主线程" << pthread_self() << " a地址:" << &a << endl;
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}