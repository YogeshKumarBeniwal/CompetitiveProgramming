// Write a function that reverses a string. The input string is given as an array
// of characters s.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swap(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void reverseString(vector<char> &s)
{
    int size = s.size();
    for (int i = 0; i < size/2; i++)
    {
        swap(s[i], s[size - 1 - i]);
    }
}

int main()
{
    vector<char> chars{'H','a','n','n','a','h'};
    reverseString(chars);

    for (int i = 0; i < chars.size(); i++)
    {
        cout << chars[i] << endl;
    }

    return 0;
}
