// Write a function that reverses a string. The input string is given as an array
// of characters s.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string reverseWords(string s)
{
    vector<int> stringLens;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            stringLens.push_back(i - 1);
        }
    }

    stringLens.push_back(s.length() - 1);
    int stringEnd = stringLens[0];
    int j = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if(i < stringEnd)
        {
            char c = s[i];
            s[i] = s[stringEnd];
            s[stringEnd] = c;
            stringEnd--;
            continue;
        }
        else if(s[i] == ' ')
        {
            j++;
            stringEnd = stringLens[j];
            continue;
        }
    }

    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";
    s = reverseWords(s);
    cout << s << endl;
    return 0;
}
