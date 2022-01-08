// Possible solution: median is shortest between all of the crabs

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("in.txt");

vector<int> positions;

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

    sort(positions.begin(), positions.end());

    int median = positions[positions.size() / 2];

    int fuel = 0;

    for (int i = 0; i < positions.size(); i++)
    {
        fuel += abs(positions[i] - median);
    }
    cout << fuel << endl;
}