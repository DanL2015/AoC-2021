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
map<string, int> visited;
int totalPaths = 0;

void dfs(string cur, vector<string> curPath, bool vTwice)
{
    for (int i = 0; i < path[cur].size(); i++)
    {
        string next = path[cur][i];
        if (next == "end")
        {
            totalPaths++;
        }
        else if (visited[next] == 0 || (visited[next] < 2 && vTwice == false))
        {
            if (islower(next[0]))
            {
                visited[next]++;
                if (visited[next] == 2)
                {
                    vTwice = true;
                }
            }
            curPath.push_back(next);
            dfs(next, curPath, vTwice);
            curPath.pop_back();
            if (islower(next[0]))
            {
                if (visited[next] == 2)
                {
                    vTwice = false;
                }
                visited[next]--;
            }
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
            visited[s1] = 0;
        }
        if (islower(s2[0]))
        {
            visited[s2] = 0;
        }
    }

    // dfs
    vector<string> emptyVector;
    emptyVector.push_back("start");
    visited["start"] = 2;
    dfs("start", emptyVector, false);

    cout << totalPaths << endl;
}