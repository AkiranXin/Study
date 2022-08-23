#include <iostream>
#include <string>

class Component
{
public:
    virtual ~Component(){}
    virtual std::string Operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    virtual std::string Operation()
    {
        return "This is ConcreteComponent";
    }
};

class Decorator : public Component
{
protected:
    Component* _component;
public:
    Decorator(Component* component) : _component(component){}
    std::string Operation()
    {
        return _component->Operation();
    }
};

class DecoratorA : public Decorator
{
public:
    DecoratorA(Component* component) : Decorator(component){}
    std::string Operation()
    {
        return "DecoratorA : -> " + Decorator::Operation();
    }
};

class DecoratorB : public Decorator
{
public:
    DecoratorB(Component* component) : Decorator(component){}
    std::string Operation()
    {
        return "DecoratorB : -> " + Decorator::Operation();
    }
};

void Client(Component* component)
{
    std::cout << "Result: " << component->Operation() << std::endl;
}

int main()
{
    Component* simple = new ConcreteComponent();
    Client(simple);

    Component* decA = new DecoratorA(simple);
    Client(decA);

    Component* decB = new DecoratorB(decA);
    Client(decB);

    delete simple;
    delete decA;
    delete decB;
    return 0;
}