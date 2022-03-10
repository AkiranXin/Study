#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class PartInfo
{
private:
    int _startIndex;
    int _endIndex;
public:
    int getStartIndex();
    void setStartIndex(int startIndex);
    int getEndIndex();
    void setEndIndex(int endIndex);
    PartInfo& operator=(PartInfo& part);
    PartInfo();
    PartInfo(int startIndex, int endIndex);
    ~PartInfo();
};

void StackQuickSort(vector<int>& vec, int startIndex, int endIndex);
int partition(vector<int>& vec, int startIndex, int endIndex);
void Show(vector<int>& vec);