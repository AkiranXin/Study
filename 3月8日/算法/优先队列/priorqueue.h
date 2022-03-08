#ifndef _PRIORQUEUE_H
#define _PRIORQUEUE_H

#include <iostream>
#include <vector>
using namespace std;

void UpNode(vector<int>& vec);
void DownNode(vector<int>& vec);
void InQueue(vector<int>& vec, int element);
int DeQueue(vector<int>& vec);
void ShowQueue(vector<int>& vec);

#endif