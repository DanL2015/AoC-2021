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

    int oxygen[12];
    int co2[12];
    vector<int> ov;
    vector<int> cv;

    for (int i = 0; i < 1000; i++)
    {
        ov.push_back(i);
        cv.push_back(i);
    }

    for (int i = 0; i < 12; i++)
    {
        int ones = 0;
        int zeros = 0;
        for (int j = 0; j < ov.size(); j++)
        {
            if (nums[ov[j]][i] == 1)
                ones++;
            if (nums[ov[j]][i] == 0)
                zeros++;
        }

        int most = 0;
        int least = 1;
        if (ones >= zeros)
        {
            most = 1;
            least = 0;
        }

        for (int j = 0; j < ov.size(); j++)
        {
            if (nums[ov[j]][i] != most)
            {
                ov.erase(ov.begin() + j);
                j--;
            }
        }
        if (ov.size() == 1)
        {
            for (int j = 0; j < 12; j++)
            {
                oxygen[j] = nums[ov[0]][j];
            }
            break;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        int ones = 0;
        int zeros = 0;
        for (int j = 0; j < cv.size(); j++)
        {
            if (nums[cv[j]][i] == 1)
                ones++;
            if (nums[cv[j]][i] == 0)
                zeros++;
        }

        int most = 0;
        int least = 1;
        if (ones >= zeros)
        {
            most = 1;
            least = 0;
        }

        for (int j = 0; j < cv.size(); j++)
        {
            if (nums[cv[j]][i] != least)
            {
                cv.erase(cv.begin() + j);
                j--;
            }
        }
        if (cv.size() == 1)
        {
            for (int j = 0; j < 12; j++)
            {
                co2[j] = nums[cv[0]][j];
            }
            break;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        cout << oxygen[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 12; i++)
    {
        cout << co2[i] << " ";
    }
    cout << endl;
}