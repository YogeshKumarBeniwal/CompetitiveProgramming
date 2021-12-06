#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version)
{
    return version >= 2147483647 ? true : false;
}

int FirstBadVersion(int n)
{
    if(n <= 1)
    {
        return n;
    }
    long long min = 1, max = n;
    long long diff = max - min, mid = 1;
    long long lastbad = LLONG_MAX;
    while (diff > 0)
    {
        if (diff == 1)
        {
            return isBadVersion(min) ? min : isBadVersion(max) ? max
                                                               : 1;
        }

        mid = (min + max) * 0.5;
        if (isBadVersion(mid))
        {
            lastbad = mid;
            max = mid;
        }
        else
        {
            if(mid+1 == lastbad)
            {

                return lastbad;
            }
            min = mid;
        }
        diff = max - min;
    }
    return 1;
}

int main()
{
    cout << FirstBadVersion(2147483648-1);
    return 0;
}
