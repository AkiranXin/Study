#include <iostream>
#include <string>

using namespace std;

class RightValue
{
public:
    int* pointer;
    int size;
    RightValue(){ pointer = new int(1);}
    RightValue(int size) : size(size){ pointer = new int[size]();}
    RightValue(RightValue&& temp) : pointer(temp.pointer)
    {
        temp.pointer = nullptr;
    }
    RightValue& operator=(RightValue&& temp)
    {
        delete [] pointer;
        pointer = temp.pointer;
        temp.pointer = nullptr;
        return *this;
    }
    RightValue& operator=(RightValue& temp)
    {
        if(this == &temp)
            return *this;
        size = temp.size;
        delete [] pointer;
        pointer = new int[size]();
        for(int i = 0; i < size; i++)
        {
            pointer[i] = temp.pointer[i];
        }
        return *this;
    }
    ~RightValue(){ delete [] pointer; cout << "Destructor!" << endl;}
};




int main(int argc, char const *argv[])
{
    RightValue r1;
    r1.pointer = new int[10]();
    r1.pointer[0] = 1;
    cout << r1.pointer[0] << endl;
    RightValue r2(move(r1));
    cout << r2.pointer[0] << endl;
    cout << (r1.pointer == nullptr) << endl;
    return 0;
}