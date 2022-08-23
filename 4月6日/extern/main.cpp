#include <iostream>
#include "extern.h"

using namespace std;

int main(int argc, char const *argv[])
{
    extern int i;
    cout << i << endl;
    return 0;
}
