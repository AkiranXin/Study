#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

static int v = 1;

void critical_section(int change_v)
{
    static mutex mtx;
    lock_guard<mutex> lock(mtx);

    v = change_v;
}


int main(int argc, char const *argv[])
{
    thread t([](){
       cout << "hello world!" << endl; 
    });
    t.join();
    
    thread t2(critical_section,2), t3(critical_section,3);
    t2.join();
    t3.join();
    cout << v << endl;
    return 0;
}
