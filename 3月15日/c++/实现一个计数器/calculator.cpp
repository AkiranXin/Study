#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include "calculator.h"

using namespace std;

int calculator::Priority(const char& c)
{
    if(c == '*' || c == '/' || c == '%')
        return 2;
    else if(c == '+' || c == '-')
        return 1; 
    else
        return 0;
}

void calculator::Change(string& s, vector<char>& res)
{
    string::iterator iter = s.begin();
    stack<char> Stack;
    //
    while (iter != s.end())
    {
        //如果是数字就直接进存储
        if(*iter <= '9' && *iter >= '0')
        {
            int sum = 0;
            while (*iter <= '9' && *iter >= '0')
            {
                sum = sum * 10 + (*iter - '0');
                iter++; 
            }
            res.push_back(sum);
            continue;
        }
        else if(Priority(*iter) == 2 || Priority(*iter) == 1)
        {
            if(Stack.empty())
            {
                Stack.push(*iter);
            }
            else
            {
                while (!Stack.empty() && Priority(*iter) <= Priority(Stack.top()))
                {
                    res.push_back(Stack.top());
                    Stack.pop();
                }
                Stack.push(*iter);  
            }
        }
        // //如果栈是空的或者读取的符号为左括号就直接入栈
        // else if(Stack.empty())
        // {
        //     Stack.push(*iter);
        // }
        // else if(*iter != ')')
        // {
        //     while (!Stack.empty() && Priority(*iter) <= Priority(Stack.top()))
        //     {
        //         res.push_back(Stack.top());
        //         Stack.pop();
        //     }
        //     Stack.push(*iter);
        // }
        else if(*iter == '(')
        {
            Stack.push(*iter);
        }
        else if(*iter == ')')
        {
            //如果查询到右括号，就一直往下看去找左括号
            while (Stack.top() != '(' && !Stack.empty())
            {
                res.push_back(Stack.top());
                Stack.pop();
            }
            //查询到左括号就把它丢了
            if(!Stack.empty())
            {
                if(Stack.top() == '(')
                    Stack.pop();
            }
        }
        iter++;
    }
    while (!Stack.empty())
    {
        res.push_back(Stack.top());
        Stack.pop();
    }
}

int calculator::calculate(string& s)
{
    
    vector<char> str;
    Change(s, str);
    stack<char> Stack;
    int temp = 0;
    vector<char>::iterator iter = str.begin();
    while (iter != str.end())
    {
        if(Priority(*iter))
            Stack.push(*iter);
        else if(Priority(*iter) == 2 || Priority(*iter) == 1)
        {
            int num2 = Stack.top() - '0';
            Stack.pop();
            int num1 = Stack.top() - '0';
            Stack.pop();
            cout << " " << num1 << *iter << " " << num2 << endl;
            switch (*iter)
            {
            case '+':
                Stack.push(num2 + num1 + '0');
                break;
            case '-':
                Stack.push(num1 - num2 + '0');
                break;
            case '*':
                Stack.push(num1 * num2 + '0');
                break;
            case '/':
                Stack.push(num1 / num2 + '0');
                break;
            case '%':
                Stack.push(num1 % num2 + '0');
                break;
            default:
                break;
            }
        }
        *iter++;
    }
    return Stack.top() - '0';
}