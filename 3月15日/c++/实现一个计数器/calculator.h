#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class calculator
{
private:
    static int Priority(const char& c);
    static void Change(string& s, vector<char>& res);
public:
    static int calculate(string& s);
};

#endif