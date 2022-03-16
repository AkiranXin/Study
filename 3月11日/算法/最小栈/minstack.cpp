#include <iostream>
#include <stack>
#include "minstack.h"

void MinStack::push(int element)
{
    mainStack.push(element);
    if(minStack.empty() || element <= minStack.top())
    {
        minStack.push(element);
    }
}

void MinStack::pop(int& element)
{
    if(minStack.top() == mainStack.top())
    {
        minStack.pop();
    }
    element = mainStack.top();
    mainStack.pop();
}

int MinStack::getMin() const
{
    if(mainStack.empty())
    {
        cout << "MinStack is empty!" << endl;
        return -9999;
    }
    return minStack.top();
}

MinStack::MinStack()
{

}

MinStack::~MinStack()
{

}