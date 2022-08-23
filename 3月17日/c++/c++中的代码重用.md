### c++中的代码重用
c++的一个主要目标是促进代码重用。公有继承是实现这种目标的机制之一，但并不是唯一的机制。

#### 包含对象成员的类
我们创建一个学生类
```c++
#ifndef _STUDENTC_H
#define _STUDENTC_H

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;
    std::ostream& arr_out(std::ostream& os) const; 
public:
    Student() : name("Null Student"), scores(){}
    explicit Student(const std::string& s)
        : name(s), scores(){}
    explicit Student(int n) : name("Nully"), scores(n){}
    Student(const std::string& s, int n)
        : name(s), scores(n) {}
    Student(const std::string& s, const ArrayDb& a)
        : name(s), scores(a) {}
    Student(const char* str, const double* pd, int n)
        : name(str), scores(pd, n){}
    ~Student() {}
    double Average() const;
    const std::string& Name() const;
    double& operator[](int i);
    double operator[](int i) const;
//friend
    //input
    friend std::istream& operator>>(std::istream& is, Student& stu);
    friend std::istream& getline(std::istream& is, Student& stu);
    //output
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};
#endif
```
这里注意一下explicit关键字的用法
因为再c++里，用一个参数的构造函数将用作从参数类型到类类型的隐式转换函数。
使用explicit可以关闭隐式转换

#### 使用被包含对象的接口
在之前的代码里我们私有方法有一个arr_out,这个是干什么的？
看一下操作符<<函数重载
```c++
ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << stu.name << ":\n";
    ...
}
```
总所周知，友元函数不是成员类，但是能访问类成员
所以operator<<(ostream& os, const Student& stu)必须是Student类的友元函数
这样才访问的是stu.name

如果你直接在外面访问stu.name，
比如 cout << stu.name; // stu.operator<<(stu.name);
所以结果是调用的operator<<(ostream&, const string&)
然而这个方法并不是Student类的友元，并且这还是私有成员，这访问不到stu.name成员。

这里定义了一个辅助的函数用于减少友元里面的编码，使其变得更整洁
```c++
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = scores.size();
    if(lim > 0)
    {
        for(int i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if(i % 5 == 4)
                os << endl; 
        }
        if(i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}
```