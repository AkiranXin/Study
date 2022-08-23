#include <iostream>

using namespace std;

class base
{
public:
    int num = 10;
    base(){}
};

class childA : virtual public base
{
public:
    int parent = 1;
    childA(){}
};

class childB : virtual public base
{
public:
    int family = 2;
    childB(){}
};

int main(int argc, char const *argv[])
{
    base b;
    childA ca;
    childB cb;



    auto res_static_cast = static_cast<base>(ca);
    cout << res_static_cast.num << endl;


    int num = 10;
    const int *a = &num;
    auto res_const_cast = const_cast<int* >(a);
    cout << "This is const_cast: \n const int* -----> int* \n The result is: " << *res_const_cast << endl;

    return 0;
}