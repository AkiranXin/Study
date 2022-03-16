#ifndef _VTBL_H
#define _VTBL_H

class Test
{

};

class VTest
{
private:

public:
    virtual void show();
};

class VTest_Son : public VTest
{
private:

public:
    virtual void Show();
    virtual void Test();
};

#endif