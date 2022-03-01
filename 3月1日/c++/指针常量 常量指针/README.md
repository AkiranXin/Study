# 指向常量的指针(常量指针)

```c++
int age = 39;
int sage = 20;
const int* pt = &age;

*pt += 1; //不允许，因为pt指针指向一个const int
cin >> *pt; //不允许，同上所述
*pt = 20;//不允许，同上

age = 20;//可以，因为age变量不是const
pt = &sage;//可以，因为只是限制了*pt
```
* pt指向一个const int，因此不能使用pt来修改这个值（*pt为const）
* 不是说指向的值是一个常量，而是对pt而言，这个值是常量

#### 不允许const的地址赋值给非const指针
```c++
const float g_earth = 9.80;
const float* pe = &g_earth; //当然允许

const float g_moon = 1.63;
float* pm = &g_moon;//不允许
```

#### 一级间接关系将非const指针赋给const指针是可以的
```c++
int age = 39;
int* pd = &age;// *pd = 41是允许的操作
const int* pt = pd;// *pt = 42是不允许的操作
//因为这样const状态很荒谬，既然都说了不允许修改值了
//还有一个pd指针能修改就离谱
```

#### 但当进入二级间接关系时，将不再安全
```c++
const int **pp2;
int *p1;
const int n = 13;
pp2 = &p1;//不允许，error: invalid conversion from 'int**' to 'const int**'
*pp2 = &n;//合理
*p1 = 10;//正确
```

>尽可能使用const
>* 这样可以避免由于无意间修改数据而导致的编程错误
>* 使用const能使函数处理const和非const实参，否则将只能接受非const数据
---

#指针常量

```c++
int age = 39;
int sage = 20;
int* const p = &age;

p = &sage;//不允许，因为限制了p指针为const，不能变动
*p = 40;//可以，因为并没有限制*p，即可以通过*p来修改指向对象的值
```

---
### 总结
const 离谁近，谁就不能修改
* (常量指针) const int *p,则 *p值不能变，但是可以修改p指向的对象。
* (指针常量) int * const p,则p的内容不能变动，但是*p可以变动，即可以通过 *p来修改指向的值。