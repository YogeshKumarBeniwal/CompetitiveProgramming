// Write a function that reverses a string. The input string is given as an array
// of characters s.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<string> SplitBySpace(string s)
{
    vector<string> tempStrings;
    string tempString = "";
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            tempStrings.push_back(tempString);
            tempString = "";
            j++;
            continue;
        }

        tempString += s[i];
    }

    tempStrings.push_back(tempString);
    return tempStrings;
}

string reverseWords(string s)
{
    vector<string> splits = SplitBySpace(s);
    int length;
    string temp = "";
    char c;
    for (int i = 0; i < splits.size(); i++)
    {
        if(temp.length() != 0) temp += ' ';
        length = splits[i].length(); 
        for (int j = 0; j < length/2; j++)
        {
            c = splits[i][j];
            splits[i][j] = splits[i][length - 1 - j];
            splits[i][length - 1 - j] = c;
        }

        temp += splits[i];
    }

    return temp;
}

int main()
{
    string s = "Let's take LeetCode contest";
    s = reverseWords(s);

    cout << s << endl;
    return 0;
}
