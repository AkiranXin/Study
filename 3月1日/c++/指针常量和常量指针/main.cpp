#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const int **pp2;
    int *p1;
    const int n = 13;
    pp2 = &p1;
    *pp2 = &n;
    *p1 = 10;
    return 0;
}
