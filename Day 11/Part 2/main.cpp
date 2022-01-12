#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("in.txt");

vector<vector<int>> octopuses;

// all directions
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, 1, 0, -1};
long long total = 0;

void update()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            octopuses[i][j]++;
        }
    }
}

void print()
{
    for (int i = 0; i < octopuses.size(); i++)
    {
        for (int j = 0; j < octopuses[i].size(); j++)
        {
            cout << octopuses[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool synchronized()
{
    int cur = octopuses[0][0];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (octopuses[i][j] != cur)
            {
                return false;
            }
        }
    }
    return true;
}

int simFlashes()
{
    int flashes = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (octopuses[i][j] > 9)
            {
                flashes++;
                octopuses[i][j] = -10000000;
                for (int k = 0; k < 8; k++)
                {
                    int cx = i + dx[k];
                    int cy = j + dy[k];
                    if (cx < 0 || cy < 0 || cx >= 10 || cy >= 10)
                    {
                        continue;
                    }
                    octopuses[cx][cy]++;
                }
            }
        }
    }
    return flashes;
}

int main()
{
    octopuses.assign(10, vector<int>());

    for (int i = 0; i < 10; i++)
    {
        string temp;
        fin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            octopuses[i].push_back(temp[j] - '0');
        }
    }

    int i = 0;
    while (!synchronized())
    {
        update();
        int curFlashes = simFlashes();
        while (curFlashes > 0)
        {
            total += curFlashes;
            curFlashes = simFlashes();
        }
        total += curFlashes;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (octopuses[j][k] < 0)
                {
                    octopuses[j][k] = 0;
                }
            }
        }
        i++;
    }
    cout << i << endl;
}