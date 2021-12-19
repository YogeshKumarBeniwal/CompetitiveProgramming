// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
// find two numbers such that they add up to a specific target number. Let these two numbers
// be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
            return {left + 1, right + 1};
        else if (sum > target)
            --right;
        else if (sum < target)
            ++left;
    }
    return {-1};
}

int main()
{
    vector<int> nums{0, 0, 3, 4};
    vector<int> indexes = twoSum(nums, 0);

    for (int i = 0; i < indexes.size(); i++)
    {
        cout << indexes[i] << endl;
    }

    return 0;
}
