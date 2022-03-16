#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a == b)
    {
        return a;
    }
        
    if((a&1) == 0 && (b&1) == 0)
    {
        return gcd(a >> 1, b >> 1) << 1;
    }
    else if((a&1) == 0 && (b&1) != 0)
    {
        return gcd(a >> 1, b);
    }
    else if((a&1) != 0 && (b&1) == 0)
    {
        return gcd(a, b >> 1);
    }
    else
    {
        int big = a > b ? a : b;
        int small = a < b ? a : b;
        return gcd(big - small, small);
    }
}

int main()
{
    int temp = gcd (12, 4);
    cout << temp << endl;
}