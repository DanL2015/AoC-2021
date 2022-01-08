#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

ifstream fin("in.txt");

vector<string> in;
vector<char> cur;
int total = 0;

char opp(char c)
{
    switch (c)
    {
    case ('<'):
        return '>';
    case ('>'):
        return '<';
    case ('['):
        return ']';
    case (']'):
        return '[';
    case ('{'):
        return '}';
    case ('}'):
        return '{';
    case ('('):
        return ')';
    case (')'):
        return '(';
    }
    return ' ';
}

bool open(char c)
{
    switch (c)
    {
    case ('<'):
        return true;
    case ('['):
        return true;
    case ('{'):
        return true;
    case ('('):
        return true;
    }
    return false;
}

int values(char c)
{
    switch (c)
    {
    case ('>'):
        return 25137;
    case (']'):
        return 57;
    case ('}'):
        return 1197;
    case (')'):
        return 3;
    }
    return 0;
}

int main()
{
    string temp;
    while (fin >> temp)
    {
        in.push_back(temp);
    }

    for (int i = 0; i < in.size(); i++)
    {
        cur.clear();
        for (int j = 0; j < in[i].size(); j++)
        {
            if (open(in[i][j]))
            {
                cur.push_back(in[i][j]);
            }
            else
            {
                if (cur.back() == opp(in[i][j]))
                {
                    cur.pop_back();
                }
                else
                {
                    // cout << in[i][j] << " " << values(in[i][j]) << endl;
                    total += values(in[i][j]);
                    break;
                }
            }
            // for (int k = 0; k < cur.size(); k++)
            // {
            //     cout << cur[k] << " ";
            // }
            // cout << endl;
        }
    }
    cout << total << endl;
}