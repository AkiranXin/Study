# 1.引用
---

定义：
* 引用是已定义变量的别名

例如:
```c++
int &rodents = rats;//rodents是rat的别名，可以通过rodents来访问rats
//rodents和rats指向相同的值和内存单元
// ！！！ 必须在声明引用变量时就初始化，并且创建后就不能更改
//引用类似于const指针
```
在数据比较大的时候（如结构和类），引用参数将很有作用

---

# 2.临时变量

这里有一个函数
```c++
double refcube(double &ra)
{
    ra *= ra * ra;
    return ra;
}

double z = refcube(x + 3.0);//错误赋值
```
由于x + 3.0不是double类型的变量，因此程序将创建一个临时的无名变量，并将其初始化为x+3.0的值，然后ra将成为该临时变量的引用

### 什么时候将创建临时变量呢？
如果引用参数时const:
* 实参的类型正确，但不是左值
* 实参的类型不正确，但可以转换成正确的类型

> 什么是左值(lvalue)？
> * 左值参数是可被引用的数据对象，例如，变量、数组元素、结构成员、引用和解除引用的指针都是左值
> * 非左值包括字面常量（用引号括起的字符串除外，它们由地址表示）和包含多项式的表达式
> * 现在常规变量和const变量都被视为左值，因为可以通过地址访问。不过常规变量属于可以修改的左值，而const变量属于不可修改的左值

#### 例子
对于以下代码：
```c++
void swapr(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
long a = 3, b = 5;
swapr(a, b);
```
根据上面的规则，发现满足第二条，实参的类型不正确但是可以被转换成正确的类型，所以将创建两个临时的变量并让其初始化为3和5，然后交换两个临时变量，a和b的值不改变。

<font color="red">如果接受引用参数的函数的意图是修改作为参数传递的变量，则创建临时变量将组织这种行为的发生</font>
<font color="blue">解决办法是，禁止创建临时变量</font>

---
#3.const
```c++
double refcube(const double &ra)
{
    return ra * ra * ra;
}

double side = 3.0;
double *pd = &pd;
double &rd = side;
long edge = 5L;

double c1 = refcube(side); // ra指向side
double c2 = refcube(rd); // ra指向rd = side
double c3 = refcube(*pd); // ra指向pd = side
double c4 = refcube(edge); // ra是临时变量
double c5 = refcube(7.0); // ra是临时变量
double c6 = refcube(side + 10.0); // ra是临时变量
```
现在来看refcube函数，该函数的目的是使用传递的值而不是修改它们，因此临时变量不会造成任何不利影响，反而会使函数在可处理的参数种类方面更通用。因此，如果将引用指定为const，c++将在必要时生成临时变量。
>实际上对于形参为const引用的c++函数，如果实参不匹配，则类似于按值传递，为确保原始数据被修改，将使用临时变量来存储值

>**应尽可能的使用const**
>将引用参数声明为常量数据的引用有三个理由
>* 使用const可以避免无意中修改数据的编程错误
>* 使用const使函数能够处理const和非const实参，否则就只能接受非const数据
>* 使用const引用能够是函数正确的生成并使用临时变量