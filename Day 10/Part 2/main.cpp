#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("in.txt");

vector<string> in;
vector<char> cur;
vector<long long> totals;

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
        return 4;
    case (']'):
        return 2;
    case ('}'):
        return 3;
    case (')'):
        return 1;
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
        long long ctotal = 0;
        cur.clear();
        bool incomplete = true;
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
                    incomplete = false;
                    continue;
                }
            }
        }
        if (incomplete)
        {
            cout << i << endl;
            for (int j = cur.size() - 1; j >= 0; j--)
            {
                ctotal *= 5;
                ctotal += values(opp(cur[j]));
            }
            totals.push_back(ctotal);
        }
    }
    sort(totals.begin(), totals.end());
    cout << totals[totals.size() / 2] << endl;
}