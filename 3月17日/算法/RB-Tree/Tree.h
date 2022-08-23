#ifndef _TREE_H
#define _TREE_H

#include <iostream>

using namespace std;

#define DEFAULTLEN 20;

class Tree
{
private:
    int* _num;
    int _num_size;
public:
    static int getHeight(int node);
    static int getDepth(int node);
    int getSize(int node) const;
    int getNumSize() const;
    void Show() const;
    Tree();
    explicit Tree(int length);
    Tree& operator=(const Tree& tr);
    ~Tree();
};

#endif