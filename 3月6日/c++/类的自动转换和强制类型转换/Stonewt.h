#ifndef _STONEWT_H
#define _STONEWT_H

class Stonewt
{
private:
    enum{ Lbs_pre_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
};


#endif