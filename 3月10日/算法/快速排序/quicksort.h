#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& vec, int startIndex, int endIndex);
int Partition(vector<int>& vec, int startIndex, int endIndex);
void Show(vector<int>& vec);

#endif