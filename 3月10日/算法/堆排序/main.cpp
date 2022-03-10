#include <iostream>
#include <vector>
#include "heapsort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{3,2,3,1,2,4,5,5,6};
    HeapSort(vec);
    Show(vec);
    return 0;
}
