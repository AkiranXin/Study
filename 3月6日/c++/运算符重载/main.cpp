#include <iostream>
#include "Time.h"
using namespace std;


int main(int argc, char const *argv[])
{
    Time t1(1, 2);
    Time t2(3, 4);
    Time t3 = t1 + t2;
    Time t4 = t2 - t1;
    t3.show();
    t4.show();
    return 0;
}
