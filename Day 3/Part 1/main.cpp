#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin("in.txt");

int nums[1000][12];

int main()
{

    // Part 1
    string s;
    int ind = 0;
    while (fin >> s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            nums[ind][i] = s[i] - '0';
        }
        ind++;
    }

    // gamma and epsilon
    int gamma[12];
    int epsilon[12];
    for (int i = 0; i < 12; i++)
    {
        int ones = 0;
        int zeros = 0;
        for (int j = 0; j < 1000; j++)
        {
            if (nums[j][i] == 1)
            {
                ones++;
            }
            if (nums[j][i] == 0)
            {
                zeros++;
            }
        }
        if (ones > zeros)
        {
            gamma[i] = 1;
            epsilon[i] = 0;
        }
        else
        {
            gamma[i] = 0;
            epsilon[i] = 1;
        }
    }

    long long dgamma = 0;
    long long depsilon = 0;
    for (int i = 11; i >= 0; i--)
    {
        dgamma += gamma[11 - i] * pow(2, i);
        depsilon += epsilon[11 - i] * pow(2, i);
    }
    cout << dgamma * depsilon << endl;
}