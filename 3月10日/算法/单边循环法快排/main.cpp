#include <iostream>
#include "singlequicksort.h"
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{4,7,3,5,6,2,8,1};
    SingleQuickSort(vec, 0 , vec.size() - 1);
    Show(vec);
    return 0;
}
