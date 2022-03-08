#include <iostream>
#include "queue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Queue<int> que(10);
    que.InQueue(1);
    que.InQueue(2);
    cout << que.DeQueue() << endl;
    que.Show();
    return 0;
}
