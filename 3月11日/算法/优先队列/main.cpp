#include <iostream>
#include <vector>
#include "MaxPriorityQueue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{10,8,9,7,1,4,6,3,2};
    enQueue(vec, 5);
    int temp;
    temp = deQueue(vec);
    cout << temp << endl;
    return 0;
}
