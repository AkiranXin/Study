#include <iostream>
#include "vtbl.h"
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "sizeof(Test) : " << sizeof(Test) << endl;
    cout << "sizeof(VTest) : " << sizeof(VTest) << endl;
    cout << "sizeof(VTest_Son) : " << sizeof(VTest_Son) << endl;
    cout << "sizeof(char*) : " << sizeof(char*) << endl;
    return 0;
}
