#include <iostream>
#include <vector>
#include "priorqueue.h"

using namespace std;

/**
 * @brief 
 * 
 * @param vec 
 */
void UpNode(vector<int>& vec)
{
    int childIndex = vec.size() - 1;//队尾下标
    int parentIndex;//获取对应的父元素
    int temp = vec[childIndex];//获取队尾元素
    //判断还有没有父节点
    while ((childIndex - 1) / 2 >= 0)
    {
        parentIndex = (childIndex - 1) / 2;
        //当父元素大于子元素的时候，说明没有必要上浮了
        if(vec[parentIndex] >= temp)
            break;
        if(vec[parentIndex] < vec[childIndex])
        {
            vec[childIndex] = vec[parentIndex];
            childIndex = parentIndex; 
        }
        //当已经到堆顶的时候还要判断一次，判断完后就退出循环
        if(childIndex == 0)
            break;
    }
    vec[childIndex] = temp;
    
}
/**
 * @brief 
 * 
 * @param vec 
 */
void DownNode(vector<int>& vec)
{
    int parentIndex = 0;//堆顶元素下标
    int temp = vec[0];//获取堆顶元素
    int leftChildIndex, rightChildIndex;//左子节点和右子节点
    int minChildIndex;//最小子节点
    while ( parentIndex * 2 + 1 < vec.size())
    {
        leftChildIndex = 2 * parentIndex + 1;
        rightChildIndex = 2 * parentIndex + 2;
        //获取最小子节点
        minChildIndex = (vec[leftChildIndex] >= vec[rightChildIndex]) ? leftChildIndex : rightChildIndex;
        //当你的父节点大于子节点的时候，就没有必要下沉了，因为已经是满足大顶堆了
        if(temp >= vec[minChildIndex])
            break;
        if(temp < vec[minChildIndex])
        {
            vec[parentIndex] = vec[minChildIndex];
            parentIndex = minChildIndex;
        }
    }
    vec[parentIndex] = temp;//别忘了最后还要给到达的位置赋值
}
/**
 * @brief 最大优先队列入队
 * 
 * @param vec 待入队队列
 * @param element 待入队元素
 */
void InQueue(vector<int>& vec, int element)
{
    vec.push_back(element);//将元素放在队列队尾
    UpNode(vec);//对其上浮
}
/**
 * @brief 最大优先队列出队
 * 
 * @param vec 待出队队列
 * @return int 堆顶元素
 */
int DeQueue(vector<int>& vec)
{
    int temp = vec[0]; //获取堆顶元素
    vec[0] = vec.back();//将队尾元素给堆顶
    vec.pop_back();//删除队尾元素
    DownNode(vec);//对堆顶元素下沉
    return temp;
}

/**
 * @brief 打印vector中的值
 * 
 * @param vec 
 */
void ShowQueue(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
