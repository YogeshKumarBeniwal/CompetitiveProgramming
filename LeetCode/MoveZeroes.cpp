//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swape(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void moveZeroes(vector<int> &nums)
{
    int fp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            continue;
        }
        swap(nums[fp], nums[i]);
        fp++;
    }
}

int main()
{
    vector<int> nums{0, 0, 0, 1, 0};
    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}