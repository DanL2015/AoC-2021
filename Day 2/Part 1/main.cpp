// forward, down, up

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("in.txt");

int main()
{
    // Part 1
    long long depth = 0;
    long long hor = 0;
    string dir;
    int val;
    while (fin >> dir)
    {
        fin >> val;
        if (dir == "forward")
            hor += val;
        if (dir == "up")
            depth -= val;
        if (dir == "down")
            depth += val;
    }
    cout << hor * depth << endl;
}