#ifndef _TIME_H
#define _TIME_H

class Time
{
private:
    int hours;
    int minutes;
public:
    Time(int h, int m);
    //操作符重载
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    void show() const;
    Time();
    ~Time();
};

#endif