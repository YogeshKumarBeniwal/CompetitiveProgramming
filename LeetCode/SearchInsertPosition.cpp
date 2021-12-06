#include <iostream>
#include <vector>
#include <string>

using namespace std;

int BinarySearchElseIndex(vector<int> &nums, int target)
{
    if (nums.size() == 1)
    {
        return nums[0] == target ? 0 : nums[0] < target ? 1
                                                        : 0;
    }

    int min = 0, max = nums.size() - 1;
    int diff = max - min;
    int mid = 0;
    while (diff >= 0)
    {
        mid = (min + max) * 0.5;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            if (diff == 0)
            {
                return mid;
            }
            max = mid == min ? min : (mid - 1);
        }
        else if (nums[mid] < target)
        {
            if (diff == 0)
            {
                return mid + 1;
            }
            min = mid == max ? max : (mid + 1);
        }

        diff = max - min;
    }

    return -1;
}

int main()
{
    vector<int> msg{2};
    for (int i = 0; i < msg.size(); i++)
    {
        cout << BinarySearchElseIndex(msg, 3) << endl;
    }
    return 0;
}