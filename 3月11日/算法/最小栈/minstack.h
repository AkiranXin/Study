#ifndef _MINSTACK_H
#define _MINSTACK_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    void push(int element);
    void pop(int& element);
    int getMin() const;
    MinStack();
    ~MinStack();
};


#endif