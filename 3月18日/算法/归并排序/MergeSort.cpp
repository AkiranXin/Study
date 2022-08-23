#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    cout << "merge: ";
    cout << "low: " << low << " mid: " << mid << " high " << high << endl;
    int l_pos = low, r_pos = high, m_pos = mid + 1, k =0;
    int *temp = new int[high - low + 1];
    while (l_pos <= mid && m_pos <= high)
    {
        if(arr[l_pos] < arr[m_pos])
            temp[k++] = arr[l_pos++];
        else
            temp[k++] = arr[m_pos++];
    }
    while (l_pos <= mid)
    {
        temp[k++] = arr[l_pos++];
    }
    while (m_pos <= high)
    {
        temp[k++] = arr[m_pos++];
    }
    for(int i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
    delete [] temp;
}

void mergeSort(int arr[],  int left, int right)
{
    cout << "mergeSort:";
    cout << "left: " << left << " right " << right << endl;
    if(left >= right)
        return ;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void Show(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {9,5,6,7,4,3,2,8,1};
    mergeSort(arr, 0, 8);
    Show(arr, 9);
     return 0;
}