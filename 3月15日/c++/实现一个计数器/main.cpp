#include <iostream>
#include <stack>
#include <string>
#include "calculator.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
    string temp = "(2+6*3+5-(3*14/7+2)*5)+3";
    int res = calculator::calculate(temp);
    cout << res << endl;
    return 0;
}
