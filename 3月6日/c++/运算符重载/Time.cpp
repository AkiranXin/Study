#include <iostream>
#include "time.h"

using namespace std;

Time::Time()
{
    hours = 0;
    minutes = 0;
}

Time::~Time()
{

}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::show() const
{
    cout << "hours: " << hours;
    cout << " minutes:" << minutes << endl;
}

Time Time::operator+(const Time& t) const
{
    Time sum;
    sum.hours = hours + t.hours;
    sum.minutes = minutes + t.minutes;
    return sum;
}

Time Time::operator-(const Time& t) const
{
    Time div;
    div.hours = hours - t.hours;
    div.minutes = minutes - t.minutes;
    return div;
}
