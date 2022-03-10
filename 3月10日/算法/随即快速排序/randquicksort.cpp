#include <iostream>
#include <vector>
#include "randquicksort.h"

using namespace std;

void RandQuickSort(vector<int>& nums, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int pivotIndex = RandPartition(nums, startIndex, endIndex);
        RandQuickSort(nums, startIndex, pivotIndex - 1);
        RandQuickSort(nums, pivotIndex + 1, endIndex);
    }
}
int RandPartition(vector<int>& nums, int startIndex, int endIndex)
{
    int pivotIndex = rand() % (endIndex - startIndex + 1) + startIndex;
    int pivot = nums[pivotIndex];
    int mark = startIndex;
    swap(nums[pivotIndex], nums[endIndex]);
    for(int i = startIndex; i <= endIndex - 1; i++)
    {
        if(pivot > nums[i])
        {
            swap(nums[mark++], nums[i]);
        }
    }
    swap(nums[mark], nums[endIndex]);
    return mark;
}


void Show(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}