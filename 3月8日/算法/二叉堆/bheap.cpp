#include <iostream>
#include <vector>
#include "bheap.h"

using namespace std;

//Fundamental Function
/**
 * @brief 节点上浮
 * 
 * @param vec 原待拆入二叉堆
 * @param childIndex 待插入子节点位置
 */
void NodeUp(vector<int>& vec, int childIndex)
{
    int temp = vec[childIndex];//临时保存下子节点的值，用于后续上浮子节点
    int parentIndex;//父节点
    //当子节点还有父节点的时候执行，也就是不能超过堆顶
    while ( (childIndex - 1) / 2 >= 0)
    {
        parentIndex = (childIndex - 1) / 2; //获取父节点值
        if(vec[parentIndex] <= temp)//如果你的子节点都大于父节点了，那就没必要判断了
            break;
        if(vec[parentIndex] > temp)
        {
            vec[childIndex] = vec[parentIndex];
            childIndex = parentIndex;
        }
        //这一步是避免死循环，当到达头节点时，还会再判断一遍，判断完一次之后就要终止判断
        if(childIndex == 0)
            break;
    }
    vec[childIndex] = temp;
    
}
/**
 * @brief 节点下沉，直接到和其子节点一直比较
 * 找到最小子节点然后和父节点交换
 * 
 * @param vec 原二叉堆
 * @param parentIndex 父节点位置
 */
void NodeDown(vector<int>& vec, int parentIndex)
{
    int temp = vec[parentIndex];//先临时保存下父节点的值，用于后续下沉父节点
    //获取子节点的值
    int leftChildIndex;//左子节点
    int rightChildIndex;//右子节点
    int minChildIndex;//左右子节点中值最小的那个下标

    //循环判断，当父节点的左子节点小于数组长度的时候才执行
    //不然就是叶子节点了，不存在子节点
    while(2 * parentIndex + 1 < vec.size())
    {
        //获取子节点的值
        leftChildIndex = 2 * parentIndex + 1;//获取左子节点
        rightChildIndex = 2 * parentIndex + 2;//获取右子节点
        //比较左右子节点的值，并将最小的那个给minChildIndex
        minChildIndex = (vec[leftChildIndex] >= vec[rightChildIndex]) ? rightChildIndex : leftChildIndex;

        //然后就是对比子节点和父节点的值，如果父节点小于最小子节点的值，则直接跳出循环
        if(temp <= vec[minChildIndex])
            break;
        //如果当前父节点的值大于子节点，则直接赋值就可以
        //其实可以不加这个判断条件，主要是为了好理解
        if(temp > vec[minChildIndex])
        {
            vec[parentIndex] = vec[minChildIndex];//将子节点的值给父节点
            parentIndex = minChildIndex;//将父节点往下移，判断下其还有没有小的子节点
        }
    }
    vec[parentIndex] = temp;
}

//Service Function
/**
 * @brief 向一个二叉堆插入，从数组尾部插入
 * 
 * @param vec 待插入的二叉堆
 * @param node 待插入的值 
 */
void InsertHeapNode(vector<int>& vec, int node)
{
    vec.push_back(node);
    NodeUp(vec, vec.size()-1);//从尾巴上插入
}
/**
 * @brief 删除二叉堆的堆顶，并且重新生成二叉堆
 * 然后让尾部元素成为堆顶，然后依次下沉
 * @param vec 待删除堆顶的二叉堆
 */
void DeleteHeapNode(vector<int>& vec)
{
    vec[0] = vec[vec.size()-1];
    vec.pop_back();
    NodeDown(vec, 0);
}
/**
 * @brief 构建二叉堆（小顶堆）
 * 
 * @param vec 待构建的无序二叉堆
 */
void BuildHeap(vector<int>& vec)
{
    //根据推论，二叉堆是一个完全二叉树
    //所以我们开始的地方是有父节点的位置，为 (length / 2) - 1
    //结果-1是为了符合数组下标
    for(int i = (vec.size() / 2) - 1; i >= 0; i--)
    {
        //只需要所有的父节点按照要求下沉就行
        NodeDown(vec, i);
    }
}


//Extra Function
/**
 * @brief 输出二叉堆
 * 
 * @param vec 待输出的二叉堆
 */
void ShowHeap(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}