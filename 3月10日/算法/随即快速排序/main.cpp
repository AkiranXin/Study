#include <iostream>
#include <vector>
#include "randquicksort.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{4,7,6,5,3,2,8,1};
    RandQuickSort(vec, 0, vec.size()-1);
    Show(vec);
    return 0;
}
