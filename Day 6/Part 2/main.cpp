#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

ifstream fin("in.txt");

vector<int> fish;
map<int, long long> mfish;

void debug()
{
    for (int i = 0; i < 9; i++)
    {
        cout << mfish[i] << " ";
    }
    cout << endl;
}

int main()
{
    string s;
    fin >> s;
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            fish.push_back(stoi(ss));
            ss = "";
        }
        else
        {
            ss += s[i];
        }
    }

    fish.push_back(stoi(ss));

    //Part 1: Brute force?
    // for (int i = 0; i < 80; i++)
    // {
    //     int newFish = 0;
    //     for (int j = 0; j < fish.size(); j++)
    //     {
    //         if (fish[j] == 0)
    //         {
    //             fish[j] = 6;
    //             newFish++;
    //         }
    //         else
    //         {
    //             fish[j]--;
    //         }
    //     }
    //     for (int j = 0; j < newFish; j++)
    //     {
    //         fish.push_back(8);
    //     }
    //     cout << fish.size() << endl;
    // }

    //Part 2: Don't worry about it
    for (int i = 0; i < 9; i++)
    {
        mfish.insert({i, 0});
    }
    for (int i = 0; i < fish.size(); i++)
    {
        mfish[fish[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        long long newFish = mfish[0];

        for (int j = 0; j < 8; j++)
        {
            mfish[j] = mfish[j + 1];
        }
        mfish[6] += newFish;
        mfish[8] = newFish;
        // debug();
    }

    long long total = 0;
    for (int i = 0; i < 9; i++)
    {
        total += mfish[i];
    }

    cout << total << endl;
}