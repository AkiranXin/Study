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
    //output
    friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};
#endif