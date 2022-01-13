#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <ctype.h>
using namespace std;

ifstream fin("in.txt");

map<string, vector<string>> path; // gives vector of adjacent paths
map<string, bool> visited;
int totalPaths = 0;

void dfs(string cur)
{
    for (int i = 0; i < path[cur].size(); i++)
    {
        string next = path[cur][i];
        if (next == "end")
        {
            totalPaths++;
        }
        else if (!visited[next])
        {
            if (islower(next[0]))
            {
                visited[next] = true;
            }
            dfs(next);
            visited[next] = false;
        }
    }
}

int main()
{
    string s;
    while (fin >> s)
    {
        string s1 = "";
        string s2 = "";
        bool ss = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                ss = true;
            }
            else
            {
                if (!ss)
                {
                    s1 += s[i];
                }
                else
                {
                    s2 += s[i];
                }
            }
        }
        path[s1].push_back(s2);
        path[s2].push_back(s1);
        if (islower(s1[0]))
        {
            visited[s1] = false;
        }
        if (islower(s2[0]))
        {
            visited[s2] = false;
        }
    }

    // dfs
    visited["start"] = true;
    dfs("start");

    cout << totalPaths << endl;
}