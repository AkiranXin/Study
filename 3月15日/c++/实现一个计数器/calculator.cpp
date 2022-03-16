#include <iostream>
#include <string>
#include <stack>
#include "calculator.h"

using namespace std;

void calculator::calculate()
{
    string::iterator iter = _str.begin();// auto iter = string.begin()
    while (iter != _str.end())
    {
        if(*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/' || *iter == '%' || *iter == '(')
        {
            
        }
    }
    
}

calculator::calculator(string& str)
{
    _str = str;
}

calculator::~calculator()
{

}