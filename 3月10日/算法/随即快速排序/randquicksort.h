#ifndef _RANDQUICKSORT_H
#define _RANDQUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

int RandPartition(vector<int>& nums, int startIndex, int endIndex);
void RandQuickSort(vector<int>& nums, int startIndex, int endIndex);
void Show(vector<int>& nums);

#endif