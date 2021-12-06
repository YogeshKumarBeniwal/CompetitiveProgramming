#include <iostream>
#include <vector>

using namespace std;

vector<int> rotate(vector<int> &nums, int k)
{
    int size = nums.size(); 
    for(int i=0; i<=k; i++)
    {
        int x = nums[size - (k-i)];
        //nums[i] += nums[size - (k-i)];
        nums[size - (k-i)] = nums[i];
        nums[i] = x;
    }

    return nums;
}

int main()
{
    vector<int> nums{-4, -3, -2, -1, 0};
    vector<int> sqs = rotate(nums, 4);

    for (int i = 0; i < sqs.size(); i++)
    {
        cout << sqs[i] << endl;
    }

    return 0;
}