// Known: 1, 4, 7, 8
// Unknown: 0, 2, 3, 5, 6, 9
// 0:
/*
    length 6
    contains 1
*/

// 2:
/*
    length 5
*/

// 3:
/*
    length 5
    3 contains 1
*/

// 5:
/*
    length 5
    6 contains 5
*/

// 6:
/*
    length 6
*/

// 9:
/*
    length 6
    contains 4
*/

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("in.txt");

vector<vector<string>> input;
vector<vector<string>> output;
vector<string> sans;
vector<int> ans;

bool stringContains(string s1, string s2) // return true if s2 entirely contains the characters in s1
{
    for (int i = 0; i < s1.size(); i++)
    {
        if (s2.find(s1[i]) == -1)
        {
            return false;
        }
    }
    return true;
}

bool sameCharStrings(string s1, string s2) // returns true if two strings have exact same character set
{
    set<char> set1;
    set<char> set2;
    for (int i = 0; i < s1.size(); i++)
    {
        set1.insert(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        set2.insert(s2[i]);
    }
    return set1 == set2;
}

int main()
{
    string s;
    while (getline(fin, s))
    {
        // parse through the input
        string temp = "";
        bool ioswitch = false;
        vector<string> tempInput;
        vector<string> tempOutput;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp == " ")
            {
                temp = "";
            }
            if (s[i] == ' ')
            {
                if (!ioswitch)
                    tempInput.push_back(temp);
                else
                    tempOutput.push_back(temp);
                temp = "";
            }
            else if (s[i] == '|')
            {
                temp = "";
                ioswitch = true;
            }
            else
            {
                temp += s[i];
            }
        }
        tempOutput.push_back(temp);
        input.push_back(tempInput);
        output.push_back(tempOutput);
    }

    // Now we have the input stored into the input array, and the output stored into the output array
    for (int i = 0; i < input.size(); i++)
    {
        // We want to create a map with key being the number and the value being the set of characters that make it up
        map<int, string> key;
        // Input the numbers we already know: 1 - 2 char, 4 - 4 char, 7 - 3 char, 8 - 7 char
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j].size() == 2)
            {
                key.insert({1, input[i][j]});
            }
            if (input[i][j].size() == 4)
            {
                key.insert({4, input[i][j]});
            }
            if (input[i][j].size() == 3)
            {
                key.insert({7, input[i][j]});
            }
            if (input[i][j].size() == 7)
            {
                key.insert({8, input[i][j]});
            }
        }

        // Next input the numbers with length 6: 0, 6, 9
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j].size() == 6)
            {
                if (key.find(9) == key.end() && stringContains(key[4], input[i][j])) // 9 contains 4
                {
                    key.insert({9, input[i][j]});
                }
                else if (key.find(0) == key.end() && stringContains(key[1], input[i][j])) // 0 contains 1
                {
                    key.insert({0, input[i][j]});
                }
                else // 6 is last
                {
                    key.insert({6, input[i][j]});
                }
            }
        }

        // Next input the numbers with length 5: 2, 3, 5
        for (int j = 0; j < input[i].size(); j++)
        {
            if (input[i][j].size() == 5)
            {
                if (key.find(5) == key.end() && stringContains(input[i][j], key[6])) // 6 contains 5
                {
                    key.insert({5, input[i][j]});
                }
                else if (key.find(3) == key.end() && stringContains(key[1], input[i][j])) // 3 contains 1
                {
                    key.insert({3, input[i][j]});
                }
                else // 2
                {
                    key.insert({2, input[i][j]});
                }
            }
        }

        string cans = "";
        for (int j = 0; j < output[i].size(); j++)
        {
            string cur = output[i][j];
            bool found = false;
            for (int k = 0; k <= 9; k++)
            {
                if (sameCharStrings(cur, key[k]))
                {
                    cans += ('0' + k);
                    found = true;
                    break;
                }
            }
        }
        sans.push_back(cans);
    }
    int total = 0;
    for (int i = 0; i < sans.size(); i++)
    {
        total += stoi(sans[i]);
    }
    cout << total << endl;
}