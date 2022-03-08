#include <iostream>
#include <vector>
#include "bheap.h"

using namespace std;

int main()
{
    vector<int> vec = {7,1,3,10,5,2,8,9,6};
    vector<int> vec2 = {1,3,2,6,5,7,8,9,10};
    BuildHeap(vec);
    ShowHeap(vec);
    // InsertHeapNode(vec2, 0);
    // ShowHeap(vec2);
    DeleteHeapNode(vec2);
    ShowHeap(vec2);
    return 0;
}
