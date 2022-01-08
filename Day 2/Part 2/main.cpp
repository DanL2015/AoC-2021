// forward, down, up

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("in.txt");

int main()
{
    long long depth = 0;
    long long hor = 0;
    long long aim = 0;
    string dir;
    int val;
    while (fin >> dir)
    {
        fin >> val;
        if (dir == "forward")
        {
            depth += val * aim;
            hor += val;
        }
        if (dir == "up")
            aim -= val;
        if (dir == "down")
            aim += val;
    }
    cout << hor * depth << endl;
}