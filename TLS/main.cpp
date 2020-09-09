#include <iostream>
#include <pthread.h>
#include <errno.h>
using namespace std;

/*
线程局部存储(TLS):

*/


void* threadFunc(void* arg)
{
    cout << "子线程" << pthread_self() << " errno地址:" << &errno << endl;
}


int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, threadFunc, NULL);
    pthread_create(&p2, NULL, threadFunc, NULL);
    cout << "主线程" << pthread_self() << " errno地址:" << &errno << endl;
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}