#ifndef _BHEAP_H
#define _BHEAP_H

#include <iostream>
#include <vector>

using namespace std;

//Fundamental Function
void NodeUp(vector<int>& vec, int childIndex);
void NodeDown(vector<int>& vec, int parentIndex);

//Service Function
void InsertHeapNode(vector<int>& vec, int node);
void DeleteHeapNode(vector<int>& vec);
void BuildHeap(vector<int>& vec);

//Extra Function
void ShowHeap(vector<int>& vec);

#endif