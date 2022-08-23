#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton
{
private:
    Singleton();
    Singleton(const Singleton& tmp);
    Singleton& operator=(const Singleton& tmp);
public:
    static Singleton* getInstance()
    {
        static Singleton instance;
        return &instance;
    }
};
