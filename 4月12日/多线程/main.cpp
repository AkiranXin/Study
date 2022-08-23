#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void thread_function(int n)
{
    std::thread::id this_id = std::this_thread::get_id();

    for(int i = 0; i < 5; i++)
    {
        cout << "Child Function thread: " << this_id << " running " << i + 1 << endl;
        this_thread::sleep_for(std::chrono::seconds(n));
    }
}

class Thread_functor
{
public:
    void operator()(int n)
    {
        std::thread::id this_id = std::this_thread::get_id();

        for(int i = 0; i < 5; i++)
        {
            cout << "Child functor thread: " << this_id << " running " << i + 1 << endl;
            this_thread::sleep_for(std::chrono::seconds(n));
        }
    }
};

int main(int argc, char const *argv[])
{
    thread my_thread(thread_function, 1);
    if(my_thread.joinable())
    {
        my_thread.join();
    }
    
    Thread_functor thread_functor;
    thread my_thread2(thread_functor, 3);
    if(my_thread2.joinable())
    {
        my_thread2.detach();
    }

    auto thread_lambda = [](int n){
        thread::id this_id = this_thread::get_id();
        for(int i = 0; i < 5; i++)
        {
            cout << "Lambda thread: " << this_id << " running " << i + 1 << endl;
            this_thread::sleep_for(std::chrono::seconds(n));
        }
    };

    thread my_thread_lambda(thread_lambda, 1);
    if(my_thread_lambda.joinable())
    {
        my_thread_lambda.join();
    }

    thread::id this_id = this_thread::get_id();
    for(int i = 0; i < 5; i++)
    {
        cout << "Main thread: " << this_id << " running " << i + 1 << endl;
        this_thread::sleep_for(std::chrono::seconds(1));
    }


    return 0;
}
