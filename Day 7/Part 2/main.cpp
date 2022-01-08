// Possible solution: mean has smallest distance between all crabs

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("in.txt");

vector<int> positions;
vector<int> sums;

int main()
{
    string s;
    fin >> s;
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            positions.push_back(stoi(ss));
            ss = "";
        }
        else
        {
            ss += s[i];
        }
    }

    int mean = 0;
    for (int i = 0; i < positions.size(); i++)
    {
        mean += positions[i];
    }
    mean = (double(mean) / positions.size());

    long long fuel = 0;

    for (int i = 0; i < positions.size(); i++)
    {
        int diff = abs(positions[i] - mean);
        fuel += (diff * (diff + 1)) / 2;
    }
    cout << fuel << endl;
}