#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

using namespace std;

template<typename T>
class Queue
{
private:
    T *array; //数组
    int length; //数组长度
    int front; //队列�?
    int rear; //队列�?
public:
    void InQueue(T element);
    T DeQueue();
    void Show();
    Queue();
    Queue(int length);
    ~Queue();
};

template<typename T>
Queue<T>::Queue()
{
    array = new T[1];//默认分配一点就�?
    array[0] = 0;
    length = 0;
    front = 0;
    rear = 0;
}

template<typename T>
Queue<T>::Queue(int length)
{
    cout << "Queue Initializing" << endl;
    array = new T[length];//默认分配一点就行
    for(int i = 0 ; i < length; i++)//初始化
    {
        array[i] = 0;
    }
    length = length;
    front = 0;
    rear = 0;
    cout << "Queue finished Initialize" << endl;
}

template<typename T>
Queue<T>::~Queue()
{
    delete [] array;//必须和new一样
}

template<typename T>
void Queue<T>::InQueue(T element)
{
    if((rear+1)%length == front)
    {
        cout << "队列已满" << endl;
    }
    array[rear] = element;
    rear = (rear + 1) % length;
}

template<typename T>
T Queue<T>::DeQueue()
{
    if(rear == front)
    {
        cout << "Queue is empty" << endl;
    }
    int deQueueElement = array[front];
    front = (front + 1) % length;
    return deQueueElement;
}

template<typename T>
void Queue<T>::Show()
{
    for(int i = front; i != rear; i = (i+1) % length)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

#endif