#include <iostream>
#include <stack>
#include <vector>
#include "stackquicksort.h"

using namespace std;

PartInfo::PartInfo(int startIndex, int endIndex)
{
    _startIndex = startIndex;
    _endIndex = endIndex;
}

PartInfo::PartInfo()
{
    _startIndex = 0;
    _endIndex = 0;
}

PartInfo::~PartInfo()
{

}

int PartInfo::getStartIndex()
{
    return _startIndex;
}

void PartInfo::setStartIndex(int startIndex)
{
    _startIndex = startIndex;
}

int PartInfo::getEndIndex()
{
    return _endIndex;
}

void PartInfo::setEndIndex(int endIndex)
{
    _endIndex = endIndex;
}

PartInfo& PartInfo::operator=(PartInfo& part)
{
    if(&part != this)
    {
        _startIndex = part.getStartIndex();
        _endIndex = part.getEndIndex();
    }
    return *this;
}

void StackQuickSort(vector<int>& vec, int startIndex, int endIndex)
{
    //用于代替递归的栈
    stack<PartInfo> QuickSortStack;
    //最开始的部分
    PartInfo beginPart(startIndex, endIndex);
    QuickSortStack.push(beginPart);
    //当栈不为空的时候进行
    while (!QuickSortStack.empty())
    {
        //获得栈顶元素并将其弹出
        PartInfo TopPart = QuickSortStack.top();
        QuickSortStack.pop();
        //获取pivot索引
        int pivotIndex = partition(vec, TopPart.getStartIndex(), TopPart.getEndIndex());
        //判断pivot左边数组
        if(TopPart.getStartIndex() < pivotIndex - 1)
        {
            PartInfo leftPart(TopPart.getStartIndex(), pivotIndex - 1);
            QuickSortStack.push(leftPart);
        }
        //判断pivot右边数组
        if(TopPart.getEndIndex() > pivotIndex + 1)
        {
            PartInfo rightPart(pivotIndex + 1, TopPart.getEndIndex());
            QuickSortStack.push(rightPart);
        }
    }
    
    
}

/**
 * @brief 使用单边循环法
 * 
 * @param vec 
 * @param startIndex 
 * @param endIndex 
 * @return int 
 */
int partition(vector<int>& vec, int startIndex, int endIndex)
{
    int mark = startIndex;
    int pivot = vec[startIndex];
    for(int i = startIndex + 1; i <= endIndex; i++)
    {
        if(pivot > vec[i])
        {
            swap(vec[++mark], vec[i]);
        }
    }
    swap(vec[mark], vec[startIndex]);
    return mark;
}

void Show(vector<int>& vec)
{
    for(int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}