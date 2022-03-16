#include <iostream>
#include <vector>

using namespace std;

void enQueue(vector<int>& vec, int key)
{
    vec.push_back(key);
    UpNode(vec);
}
int deQueue(vector<int>& vec)
{
    if(vec.empty())
    {
        cout << "vector is empty!" << endl;
        return 0;
    }
    int head = vec[0];
    int tail = vec.size() - 1;
    vec[0] = vec[tail];
    DownNode(vec);
    return head;

}
void UpNode(vector<int>& vec)
{
    int childIndex = vec.size() - 1;
    int parentIndex = (childIndex - 1) / 2;
    int temp = vec[childIndex];
    while ((childIndex - 1) / 2 > 0 && temp > vec[parentIndex])
    {
        vec[childIndex] = vec[parentIndex];
        childIndex = parentIndex;
        parentIndex = (parentIndex - 1) / 2;
    }
    vec[childIndex] = temp;
    
}

void DownNode(vector<int>& vec)
{
    int parentIndex = 0;
    int temp = vec[parentIndex];
    int LeftChildIndex = 1;
    int RightChildIndex = LeftChildIndex;
    int minChildIndex;
    while (LeftChildIndex < vec.size())
    {
        if(LeftChildIndex + 1 < vec.size())
        {
            RightChildIndex = LeftChildIndex + 1;
        }
        minChildIndex = (LeftChildIndex >= RightChildIndex) ? LeftChildIndex : RightChildIndex;
        if(temp >= vec[minChildIndex])
        {
            break;
        }
        if(temp < vec[minChildIndex])
        {
            vec[parentIndex] = vec[minChildIndex];
            parentIndex = minChildIndex;
            minChildIndex = 2 * minChildIndex + 1;
        }
    }
    vec[parentIndex] = temp;
    
}