#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <string>
using namespace std;

/*
线程局部存储(TLS):

注意：如果定义 __thread 变量时就要进行初始化，那么其只能是一个常量

*/


// static __thread string s("helloWorld"); //ERROR! 不能调用构造函数
// static __thread string *s = new string("hello"); //ERROR!   只能使用编译期常量
static __thread string *s = NULL; //ok, 需要之后进行手工初始化


void* threadFunc(void* arg)
{
    s = new string("hello");
    cout << "子线程" << pthread_self() << " s地址:" << s << endl;
}


int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, threadFunc, NULL);
    pthread_create(&p2, NULL, threadFunc, NULL);
    cout << "主线程" << pthread_self() << " s地址:" << s << endl;
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}