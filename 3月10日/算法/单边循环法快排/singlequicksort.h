#ifndef _SINGLEQUICKSORT_H
#define _SINGLEQUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

void SingleQuickSort(vector<int>& vec, int startIndex, int endIndex);
int partition(vector<int>& vec, int startIndex, int endIndex);
void Show(vector<int>& vec);

#endif