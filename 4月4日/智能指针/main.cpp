#include <iostream>
#include <memory>
using namespace std;

class TestB;

class TestA
{
public:
    weak_ptr<TestB> _ptr;
public:
    TestA(){}
    ~TestA(){}
};

class TestB
{
public:
    weak_ptr<TestA> _ptr;
public:
    TestB(){}
    ~TestB(){}
};

int main(int argc, char const *argv[])
{
    shared_ptr<TestB> pb = make_shared<TestB>();
    shared_ptr<TestA> pa = make_shared<TestA>();

    pb->_ptr = pa;
    pa->_ptr = pb;
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;


    shared_ptr<int> sp1, sp2;
    weak_ptr<int> wp;

    sp1 = make_shared<int>(20);
    wp = sp1;

    sp2 = wp.lock();
    sp1.reset();

    sp1 = wp.lock();
    cout << "*sp1 = " << *sp1 << endl;
    cout << "*sp2 = " << *sp2 << endl;
    return 0;
}