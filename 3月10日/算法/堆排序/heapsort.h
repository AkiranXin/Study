#ifndef _HEAPSORT_H
#define _HEAPSORT_H

#include <iostream>
#include <vector>

using namespace std;

void HeapSort(vector<int>& vec);

void NodeDown(vector<int>& vec, int parentIndex, int length);

void Show(vector<int>& vec);

#endif