#include <iostream>
#include <vector>
#include <string>

using namespace std;

int BinarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 1)
    {
        return nums[0] == target ? 0 : -1;
    }

    int i = 0, j = nums.size() - 1;
    int m = 0;
    if (nums[i] > target || nums[j] < target)
    {
        return -1;
    }
    while (j - i > 0)
    {
        m = (i + j) * 0.5;
        if (nums[m] == target)
        {
            return m;
        }
        else if (nums[m] > target)
        {
            j = m;
        }
        else if (nums[m] < target)
        {
            i = m;
        }

        if (j - i == 1)
        {
            return nums[j] == target ? j : nums[i] == target ? i : -1;
        }
    }
    return -1;
}

int main()
{
    vector<int> msg{2, 5};
    for (int i = 0; i < msg.size(); i++)
    {
        cout << BinarySearch(msg, msg[i]) << endl;
    }
    return 0;
}