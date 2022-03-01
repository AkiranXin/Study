#include <iostream>

using namespace std;

/**
 * @brief 内联函数
 * 内联函数的运行速度比常规函数稍快，但是代价是占用更多的内存空间
 * 应当有选择的使用内联函数。
 * 如果执行函数代码的时间比处理函数调用机制的时间长
 * 则节省的时间将只占整个过程的很小一部分
 * 如果代码执行时间很短，则内联调用可以节省非内联调用使用的大部分时间
 * 除非该函数经常被调用，不然节省的时间绝对值并不大
 * 
 * 常规函数在执行时，会转移到独立空间
 * 内联函数则会用内联代码直接替用函数部分
 * 
 * ！！！内联函数不能递归
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

inline double sqaure(double x){return x * x;}

int main(int argc, char const *argv[])
{
    double a,b;
    double c = 13.0;
    a = sqaure(5);
    b = sqaure(4.5 + 7.5);
    cout << a << " " << b << " " << c << endl;
    
    return 0;
}
