#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GetNewIndex(int current, int steps, int size)
{
    int s = current + steps;
    size -= 1;

    return s > size ? s - size - 1 : s;
}

int GetMinSteps(int steps, int size)
{
    float f = (float)steps / (float)size;
    f = f - (int)f;

    return round(f * size);
}

void rotate(vector<int> &nums, int k)
{
    int size = nums.size();

    if (size == 1 || k == 0)
    {
        return;
    }

    int minSteps = k > size ? GetMinSteps(k, size) : k;

    if (minSteps == size)
    {
        return;
    }

    int temp = nums[0], ni;

    int l1 = 1, l2 = 1;
    bool isFirst = true;
    for (int i = 0; i < l1; i++)
    {
        ni = i;
        temp = nums[i];
        for (int j = 0; j < l2; j++)
        {
            ni = GetNewIndex(ni, minSteps, size);
            temp = temp + nums[ni];
            nums[ni] = temp - nums[ni];
            temp = temp - nums[ni];
            if (ni == 0)
            {
                l1 = size / l2;
                isFirst = false;
                break;
            }
            else if (isFirst)
            {
                l2++;
            }
        }
    }
}

int main()
{
    vector<int> nums{1,2,3,4,5,6};
    rotate(nums, 1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}