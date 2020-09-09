#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <string>
#include <vector>
using namespace std;

/*
线程局部存储(TLS):

每一个线程都要拥有自己的string类型, 然后再在主线程汇总
*/

vector<string*> vec;
static __thread string *s = NULL; //ok, 需要之后进行手工初始化

void* threadFunc(void* arg)
{
    s = new string("hello");
    cout << "子线程" << pthread_self() << " s地址:" << s << endl;
    vec.push_back(s);
}


int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, threadFunc, NULL);
    pthread_create(&p2, NULL, threadFunc, NULL);
    cout << "主线程" << pthread_self() << " s地址:" << s << endl;
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    cout << "-----------" << endl;

    for (auto& e: vec)
    {
        cout << *e << endl;
        cout << e << endl;
    }
    return 0;
}