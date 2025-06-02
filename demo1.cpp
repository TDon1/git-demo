#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>  // ⚠️ 必须包含这个头文件才能使用 std::mutex

using namespace std;

std::mutex mtx;  // 全局互斥锁

void print()
{
    for(int i = 0; i < 10; i++)
    {
        mtx.lock();         // 加锁
        cout << i << endl;
        mtx.unlock();       // 解锁
        sleep(1);
    }
}

int main()
{
    thread t1(print), t2(print);
    t1.join();
    t2.join();
    return 0;
}