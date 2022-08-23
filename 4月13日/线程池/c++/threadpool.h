#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <iostream>
#include <mutex>
#include <queue>
#include <functional>
#include <future>
#include <thread>
#include <utility>
#include <vector>

template<typename T>
class SafeQueue
{
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
public:
    SafeQueue(){}
    SafeQueue(SafeQueue && other){}
    ~SafeQueue(){}

    bool empty()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    int size()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T &t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    bool dequeue(T &t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_queue.empty())
            return false;
        t = std::move(m_queue.front());
        return true;
    }
};

class ThreadPool
{
private:
    class ThreadWorker
    {
    private:
        int m_id; //工作id
        ThreadPool *m_pool;//所属线程池
    public:
        ThreadWorker(ThreadPool *pool, const int id) : m_pool(pool), m_id(id)
        {

        }

        void operator()()
        {
            std::function<void()> func; //定义基础函数类

            bool dequeued; //是否正在取出队列中元素

            while(!m_pool -> m_shutdown)
            {
                {
                    //为线程环境加锁，互斥访问工作线程的休眠和唤醒
                    std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);

                    //如果任务队列为空，则阻塞当前线程
                    if(m_pool->m_queue.empty())
                    {
                        m_pool->m_condition_lock.wait(lock);
                    }

                    dequeued = m_pool->m_queue.dequeue(func);
                }
                if(dequeued)
                    func();
            }
        }
    };

    bool m_shutdown; //线程池是否关闭
    SafeQueue<std::function<void>> m_queue; //执行函数安全队列，任务队列

    std::vector<std::thread> m_threads; //工作线程队列

    std::mutex m_contiditonal_mutex; //线程休眠互斥锁

    std::condition_variable m_conditional_lock;//线程环境条件变量，让线程休眠或唤醒

public:
    ThreadPool(const int n_threads = 4)
        : m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false)
    {
        
    }

    ThreadPool(const ThreadPool &) = delete;

    ThreadPool(ThreadPool &&) = delete;

    ThreadPool &operator=(const ThreadPool &) = delete;

    ThreadPool &operator=(ThreadPool &&) = delete;

    void init()
    {
        for(int i = 0; i < m_threads.size(); i++)
        {
            m_threads.at(i) = std::thread(ThreadWorker(this, i));
        }
    }

    void shutdown()
    {
        m_shutdown = true;
        m_conditional_lock.notify_all();

        for(int i = 0; i < m_threads.size(); i++)
        {
            if(m_threads.at(i).joinable())
            {
                m_threads.at(i).join();
            }
        }
    }
};


#endif