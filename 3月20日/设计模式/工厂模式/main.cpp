#include <iostream>
#include <vector>

using namespace std;

enum CTYPE {COREA, COREB}; 


/**
 * @brief 简单工厂模式
 * 
 */
class SimpleCore
{
public:
    virtual void show() = 0;
};

class SimpleCoreA : public SimpleCore
{
public:
    void show(){cout << "SimpleCore: A" << endl;}
};

class SimpleCoreB : public SimpleCore
{
public:
    void show(){cout << "SimpleCore: B" << endl;}
};

class SimpleFactory
{
public:
    SimpleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if(ctype == COREA)
        {
            return new SimpleCoreA();
        }
        else if(ctype == COREB)
        {
            return new SimpleCoreB();
        }
        else 
            return nullptr;
    }
};



/**
 * @brief 工厂方法模式
 * 
 */
class FunctionCore
{
public:
    virtual void show() = 0;
};

class FunctionCoreA : public FunctionCore
{
public:
    void show(){cout << "FunctionCore: A" << endl;}
};

class FunctionCoreB : public FunctionCore
{
public:
    void show(){cout << "FunctionCore: B" << endl;}
};

class FunctionFactory
{
public:
    virtual FunctionCore* CreateCore() = 0;
};

class FunctionFactoryA : public FunctionFactory
{
public:
    FunctionCore* CreateCore()
    {
        return new FunctionCoreA();
    }
};

class FunctionFactoryB : public FunctionFactory
{
public:
    FunctionCore* CreateCore()
    {
        return new FunctionCoreB();
    }
};

/**
 * @brief 抽象工厂模式
 * 
 */
class AbstractSingleCore
{
public:
    virtual void show() = 0;
};

class AbstractSingleCoreA : public AbstractSingleCore
{
public:
    void show(){cout << "AbstractSingleCore: A" << endl;}
};

class AbstractSingleCoreB : public AbstractSingleCore
{
public:
    void show(){cout << "AbstractSingleCore: B" << endl;}
};

class AbstractMultiCore
{
public:
    virtual void show() = 0;
};

class AbstractMultiCoreA : public AbstractMultiCore
{
public:
    void show(){cout << "AbstractMultiCore: A" << endl;}
};

class AbstractMultiCoreB : public AbstractMultiCore
{
public:
    void show(){cout << "AbstractMultiCore: B" << endl;}
};

class AbstractFactory
{
public:
    virtual AbstractSingleCore* CreateSingleCore() = 0;
    virtual AbstractMultiCore* CreateMultiCore() = 0;
};

class AbstractFactoryA : AbstractFactory
{
public:
    AbstractSingleCore* CreateSingleCore()
    {
        return new AbstractSingleCoreA();
    }
    AbstractMultiCore* CreateMultiCore()
    {
        return new AbstractMultiCoreA();
    }  
};

class AbstractFactoryB : AbstractFactory
{
public:
    AbstractSingleCore* CreateSingleCore()
    {
        return new AbstractSingleCoreB();
    }
    AbstractMultiCore* CreateMultiCore()
    {
        return new AbstractMultiCoreB();
    }  
};


int main(int argc, char const *argv[])
{
    //简单工厂模式
    SimpleFactory simpleFac;
    SimpleCore* Core1 = simpleFac.CreateSingleCore(COREA);
    Core1->show();
    
    //工厂方法模式
    FunctionFactoryA funcFacA;
    FunctionCore* funcCoreA1 = funcFacA.CreateCore();
    funcCoreA1->show();
    
    //抽象工厂模式
    AbstractFactoryA AbFacA;
    AbstractSingleCore* AbSCore1 = AbFacA.CreateSingleCore();
    AbSCore1->show();

    return 0;
}
