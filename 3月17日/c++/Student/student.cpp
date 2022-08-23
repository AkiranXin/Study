#include <iostream>
#include <string>
#include "student.h"

using namespace std;

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

ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}