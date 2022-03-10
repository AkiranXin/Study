#include <iostream>
#include <vector>
#include "heapsort.h"

using namespace std;

void HeapSort(vector<int>& vec)
{
    //这一步是先将无序的数组搭建成二叉堆（小顶堆）
    for(int i = (vec.size() / 2) - 1; i >= 0; i--)
    {
        NodeDown(vec, i, vec.size());
    }
    /**
     * @brief 因为建成的是小顶堆，
     * 所以不断地将小顶堆的堆顶放到末尾
     * 则重新建成的小顶堆也会将最小的元素放到堆顶
     * 然后不断重复，最后就会变成大顶堆，且有序
     * 
     * @param i  
     */
    for(int i = vec.size() - 1; i > 0; i--)
    {
        swap(vec[0], vec[i]);
        NodeDown(vec, 0, i);
    }
}

void NodeDown(vector<int>& vec, int parentIndex, int length)
{
    int temp = vec[parentIndex];
    int LeftIndex;
    int RightIndex;
    int MinIndex;
    while ( (2 * parentIndex + 1) < length )
    {
        LeftIndex =  2 * parentIndex + 1;
        RightIndex = LeftIndex;
        if( 2 * parentIndex + 2 < length)
        {
            RightIndex = 2 * parentIndex + 2;
        }
        MinIndex = (vec[LeftIndex] >= vec[RightIndex]) ? RightIndex : LeftIndex;
        if(vec[MinIndex] >= temp)
            break;
        if(vec[MinIndex] < temp)
        {
            vec[parentIndex] = vec[MinIndex];
            parentIndex = MinIndex;
        }
        vec[parentIndex] = temp;
    }
    
}

void Show(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}