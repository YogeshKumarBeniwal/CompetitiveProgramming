#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        nums[i] *= nums[i];
    }

    int fp = -1, bp = -1;

    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            fp = size - 1;
            bp = size - 2;
            break;
        }

        if (nums[i] >= nums[i + 1])
        {
            continue;
        }

        fp = i;
        bp = i == 0 ? -1 : i - 1;
        break;
    }

    if (bp == -1)
    {
        return nums;
    }

    vector<int> vect(size);

    int pointer = 0;

    while (pointer < size)
    {
        if (fp == size || bp >= 0 && nums[fp] > nums[bp])
        {
            vect[pointer] = nums[bp];
            bp--;
        }
        else
        {
            vect[pointer] = nums[fp];
            fp++;
        }

        pointer++;
    }

    return vect;
}

int main()
{
    vector<int> nums{-4, -3, -2, -1, 0};
    vector<int> sqs = sortedSquares(nums);

    for (int i = 0; i < sqs.size(); i++)
    {
        cout << sqs[i] << endl;
    }

    return 0;
}