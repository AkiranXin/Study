#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
    }
    return -1;
}

int left_bound(vector<int>& nums, int target)
{
    if(nums.empty())
        return -1;
    int left = 0;
    int right = nums.size()-1;
    
    while (left <= right)
    {
        int mid = left + (right - mid) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target)
            right = mid - 1;
    }
    //判定是否符合条件
    if(left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

int right_bound(vector<int>& nums, int target)
{
    if(nums.empty())
        return -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target)
            left = mid + 1;
    }
    //判定是否符合条件
    if(right < 0 || nums[right] != target)
        return -1;
    return right;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2,3,3,3,7,8,9};
    cout << left_bound(nums, 3) << endl;
    cout << right_bound(nums, 3) << endl;
    return 0;
}
