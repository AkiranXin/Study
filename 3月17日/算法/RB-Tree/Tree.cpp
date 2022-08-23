#include <iostream>
#include "Tree.h"

using namespace std;

int Tree::getHeight(int node) 
{
    return 0;
}
int Tree::getDepth(int node) 
{
    return 0;
}
int Tree::getSize(int node) const
{
    return 0;
}
int Tree::getNumSize() const
{
    return _num_size;
}
void Tree::Show() const
{
    for(int i = 0; i < _num_size; i++)
    {
        cout << _num[i] << " ";
    }
    cout << endl;
}
Tree::Tree()
{
    _num_size = DEFAULTLEN;
    _num = new int[_num_size];
}
Tree::Tree(int length)
{
    _num_size = length;
    _num = new int[_num_size];
    for(int i = 0; i < _num_size; i++)
    {
        _num[i] = i;
    }
}
Tree& Tree::operator=(const Tree& tr)
{
    if(this == &tr)
        return *this;
    delete [] _num;
    _num_size = tr.getNumSize();
    _num = new int[_num_size];
    for(int i = 0; i < _num_size; i++)
    {
        _num[i] = tr._num[i];
    }
    return *this;
}
Tree::~Tree()
{
    delete [] _num;
}
