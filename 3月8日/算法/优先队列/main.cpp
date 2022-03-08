#include <iostream>
#include <vector>
#include "priorqueue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec = {10,8,9,7,1,4,6,3,2};
    InQueue(vec, 5);
    ShowQueue(vec);
    DeQueue(vec);
    ShowQueue(vec);
    return 0;
}
