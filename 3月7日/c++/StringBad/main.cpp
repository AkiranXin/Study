#include <iostream>
#include "stringbad.h"

using namespace std;

void callme1(StringBad& rsb)
{
    cout << "String passed by reference:\n";
    cout << "  \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "  \"" << sb << "\"\n";
}

int main(int argc, char const *argv[])
{
    StringBad sb;
    StringBad ysb = sb;
    callme2(sb);
    return 0;
}
