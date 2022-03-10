#include <iostream>
#include "quicksort.h"

using namespace std;

void QuickSort(vector<int>& vec, int startIndex, int endIndex)
{
    //先声明递归结束条件
    if(startIndex >= endIndex)
    {
        return ;
    }
    int pivotIndex = Partition(vec, startIndex, endIndex);
    QuickSort(vec, startIndex, pivotIndex - 1);
    QuickSort(vec, pivotIndex + 1, endIndex);
    
}

int Partition(vector<int>& vec, int startIndex, int endIndex)
{
    int pivot = vec[startIndex];//取数组的首元素为基准元素
    int left = startIndex;
    int right = endIndex;

    while (left != right)
    {
        //先是控制right左移
        //满足条件是left和right不相等时并且数组元素大于基准元素pivot时
        while (left < right && pivot < vec[right])
        {
            right--;
        }
        //然后控制left右移
        while(left < right && pivot >= vec[left])
        {
            left++;
        }
        //然后交换left和right元素
        if(left < right)
        {
            int temp = vec[left];
            vec[left] = vec[right];
            vec[right] = temp;
        }        
    }
    //此时应该left和right重合，并且和pivot交换元素
    vec[startIndex] = vec[left];
    vec[left] = pivot;

    return left;
}

void Show(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}