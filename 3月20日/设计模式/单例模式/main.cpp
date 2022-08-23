#include <iostream>
#include <pthread.h>

using namespace std;

//not safe
class Singleton1
{
private:
    static Singleton1* instance;
    Singleton1()
    {
        cout << "you called an construction1" << endl;
    }
    Singleton1(const Singleton1& tmp){}
    Singleton1& operator=(const Singleton1& tmp){}
public:
    static Singleton1* getInstance()
    {
        if(instance == nullptr)
            instance = new Singleton1();
        return instance;
    }
};

//not safe not good
class Singleton2
{
private:
    static pthread_mutex_t mutex;
    static Singleton2* instance;
    Singleton2()
    {
        pthread_mutex_init(&mutex, NULL);
        cout << "you called an construction2" << endl;
    }
    Singleton2(const Singleton2& tmp){}
    Singleton2& operator=(const Singleton2& tmp){}
public:
    static Singleton2* getInstance()
    {
        pthread_mutex_lock(&mutex);
        if(instance == nullptr)
            instance = new Singleton2();
        pthread_mutex_unlock(&mutex);
        return instance;
    }
};

//not safe
class Singleton3
{
private:
    Singleton3()
    {
        cout << "you called an construction3" << endl;
    }
    Singleton3(const Singleton3& tmp){}
    Singleton3& operator=(const Singleton3& tmp){}
public:
    static Singleton3* getInstance()
    {
        static Singleton3 instance;
        return &instance;
    }
};

// good
class Singleton4
{
private:
    static Singleton4* instance;
    Singleton4(const Singleton4& tmp){}
    Singleton4& operator=(const Singleton4& tmp){}
protected:
    Singleton4()
    {
        cout << "you called an construction4" << endl;
    }
public:
    static Singleton4* getInstance()
    {
        return instance;
    }
};

//good
class Singleton6
{
private:
    static Singleton6* instance;
    static pthread_mutex_t mutex;
    Singleton6()
    {
        cout << "Singleton6 constructed!" << endl;
    }
    Singleton6(const Singleton6& tmp){}
    Singleton6& operator=(const Singleton6& tmp){}
public:
    static Singleton6* getInstance()
    {
        if(instance == nullptr)
        {
            pthread_mutex_lock(&mutex);
            if(instance == nullptr)
            {
                instance = new Singleton6();
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }
};

Singleton1* Singleton1::instance = nullptr;

Singleton2* Singleton2::instance = nullptr;
pthread_mutex_t Singleton2::mutex;

Singleton4* Singleton4::instance = new Singleton4();

Singleton6* Singleton6::instance = nullptr;
pthread_mutex_t Singleton6::mutex;

int main(int argc, char const *argv[])
{
    Singleton2* temp1 = Singleton2::getInstance();
    Singleton3* temp3 = Singleton3::getInstance();
    Singleton4* temp4 = Singleton4::getInstance();
    Singleton6* temp6 = Singleton6::getInstance();
    return 0;
}
