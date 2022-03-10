#include <iostream>
#include <vector>
#include "singlequicksort.h"

using namespace std;

void SingleQuickSort(vector<int>& vec, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int pivotIndex = partition(vec, startIndex, endIndex);
        SingleQuickSort(vec, startIndex, pivotIndex - 1);
        SingleQuickSort(vec, pivotIndex + 1, endIndex);
    }
}

int partition(vector<int>& vec, int startIndex, int endIndex)
{
    int pivot = vec[startIndex];
    int mark = startIndex;//使用mark标记将小于pivot的元素移动到左边
    //单边循环
    for(int i = startIndex + 1; i <= endIndex; i++)
    {
        if(vec[i] < pivot)
        {
            swap(vec[i], vec[++mark]);
        }
    }
    swap(vec[mark], vec[startIndex]);//将pivot标准放在所有小于pivot元素的右边
    return mark;
}

void Show(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}