#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("in.txt");

vector<vector<int>> heightmap;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main()
{
    string s;
    while (fin >> s)
    {
        vector<int> row;
        for (int i = 0; i < s.size(); i++)
        {
            row.push_back(s[i] - '0');
        }
        heightmap.push_back(row);
    }

    int total = 0;

    for (int i = 0; i < heightmap.size(); i++)
    {
        for (int j = 0; j < heightmap[i].size(); j++)
        {
            int adj = 0;
            for (int k = 0; k < 4; k++)
            {
                int cx = dx[k] + i;
                int cy = dy[k] + j;
                if (cx < 0 || cy < 0 || cx >= heightmap.size() || cy >= heightmap[i].size())
                {
                    adj++;
                    continue;
                }
                if (heightmap[cx][cy] > heightmap[i][j])
                {
                    adj++;
                }
            }
            if (adj == 4)
            {
                total += 1;
                total += heightmap[i][j];
            }
        }
    }
    cout << total << endl;
}