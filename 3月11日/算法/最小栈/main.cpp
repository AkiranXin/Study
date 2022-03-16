#include <iostream>
#include <stack>
#include "minstack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    MinStack MinStack;
    MinStack.push(1);
    MinStack.push(4);
    MinStack.push(3);
    int element;
    MinStack.pop(element);
    cout << element << endl;
    cout << MinStack.getMin() << endl;
    return 0;
}
