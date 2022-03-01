#include <iostream>

using namespace std;

const double *f1(const double *ar, int n)
{
    return ar;
}

const double *f2(const double ar[], int n)
{
    return ar+1;
}

const double *f3(const double ar[], int n)
{
    return ar+2;
}

void MainPulate()
{
    double array[5] = {1,2,3,4,5};
    const double *(*p1)(const double*, int n) = f1;//函数指针指向f1函数
    cout << (*p1)(array, 5) << " : "  << *(*p1)(array,5) << endl;//使用函数指针相当于调用函数
    auto p2 = f2;//c++11自动推导
    cout << p2(array, 5) << " : " << *p2(array,5) << endl;
    
    //函数指针数组
    const double * (*pa[3])(const double*, int) = {f1,f2,f3};
    auto pb = pa;
    //使用数组
    const double *px = pa[0](array,5);
    const double *py = pa[1](array,5);
    cout << *px << " " << *py << endl;
    auto pc = &pa;
}


int main(int argc, char const *argv[])
{
    MainPulate();
    return 0;
}
