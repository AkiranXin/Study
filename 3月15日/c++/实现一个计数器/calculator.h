#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class calculator
{
private:
    string _str;
    stack<int> _stackNum; //数字栈
    stack<char> _stackChar; //符号栈
public:
    void calculate();
    calculator(string& str);//此构造函数会自动成为复制构造函数，如果有需要的话
    ~calculator();
};

#endif