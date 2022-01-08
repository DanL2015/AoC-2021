#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("in.txt");

int main()
{
    // Part 1
    int prev;
    fin >> prev;
    int next;
    int total = 0;
    while (fin >> next)
    {
        if (next > prev)
        {
            total++;
        }
        prev = next;
    }
    cout << total << endl;
}