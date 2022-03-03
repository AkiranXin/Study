### this指针
> 假设这里有一个股票类，从show()的输出我们可以知道持有的哪一支股票价格最高，但由于程序无法直接访问total_val,因此无法做出判断。要让程序知道存储的数据，最直接的就是返回一个值，通常使用内联代码
```c++
class Stock
{
private:
    ...
    double total_val;
    ...
public:
    double total() const{ return total_val; }
    ...
}
```

>为了能将两个要比较的对象提供给成员函数，假设命名一个函数topval()，则Stock1.topval()将访问第一个对象的数据，Stock2.topval()将访问第二个对象打的数据。同时，将要比较的对象通过参数传给方法，出于效率考虑，可以使用引用 const Stock&
```c++
const Stock& :: Stock::topval(const Stock& s) const
{
    if(s.total_val > total_val)
    {
        return s;
    }
    else
    {
        //返回的不是this，因为this是对象的地址而不是对象本身
        //所以使用*this解引用
        return *this;
    }
}
//第一个const表示返回的是一个const Stock引用，因为这是比较两个对象
//所以返回也应该是两对象的其中一个
//第二个const表示传入的参数是const对象，表明不会修改显示访问的对象
//第三个const表示不会修改隐式访问的对象
...
top = stock1.topval(stock2);
```
> *this指针就是表明指向调用成员函数的对象，this被作为隐藏参数传递给方法。
> 一般来说所有的类方法都使用this指针设置为调用它的对象的地址,每个成员函数都有一个this指针指向调用对象。
> 实际上total_val应该是this->total_val