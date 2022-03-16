#ifndef _MAXPRIORITYQUEUE_H
#define _MAXPRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

void enQueue(vector<int>& vec, int key);
int deQueue(vector<int>& vec);
void UpNode(vector<int>& vec);
void DownNode(vector<int>& vec);

#endif