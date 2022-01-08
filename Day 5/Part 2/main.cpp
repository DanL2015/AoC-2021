// Quick solution? store in map, key = ordered pair, element = number of appearances

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("in.txt");
map<pair<int, int>, int> seafloor;
vector<pair<pair<int, int>, pair<int, int>>> input;

int main()
{
    string s1;
    string temp;
    string s2;
    while (fin >> s1 >> temp >> s2)
    {
        pair<pair<int, int>, pair<int, int>> cur;
        string s11 = "";
        string s12 = "";
        bool s = false;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ',')
            {
                s = true;
                continue;
            }
            (!s ? s11 += s1[i] : s12 += s1[i]);
        }
        cur.first.first = stoi(s11);
        cur.first.second = stoi(s12);
        string s21 = "";
        string s22 = "";
        s = false;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ',')
            {
                s = true;
                continue;
            }
            (!s ? s21 += s2[i] : s22 += s2[i]);
        }
        cur.second.first = stoi(s21);
        cur.second.second = stoi(s22);

        input.push_back(cur);
    }

    for (int i = 0; i < input.size(); i++)
    {
        pair<int, int> start = input[i].first;
        pair<int, int> end = input[i].second;
        // Discards diagonals
        // if (start.first != end.first && start.second != end.second) continue;
        // Just to make sure that the start one is lower than the end point
        if (start.first > end.first || start.second > end.second)
        {
            end = input[i].first;
            start = input[i].second;
        }
        if (start.first == end.first)
        {
            for (int i = start.second; i <= end.second; i++)
            {
                pair<int, int> curCoord = {start.first, i};
                if (seafloor.find(curCoord) == seafloor.end())
                {
                    seafloor.insert({curCoord, 1});
                }
                else
                {
                    seafloor[curCoord]++;
                }
            }
        }
        else if (start.second == end.second)
        {
            for (int i = start.first; i <= end.first; i++)
            {
                pair<int, int> curCoord = {i, start.second};
                if (seafloor.find(curCoord) == seafloor.end())
                {
                    seafloor.insert({curCoord, 1});
                }
                else
                {
                    seafloor[curCoord]++;
                }
            }
        }
        else // diagonals :(
        {
            // either ++ or +- direction
            if (end.first > start.first && end.second > start.second) //++
            {
                for (int i = 0; start.first + i <= end.first; i++)
                {
                    pair<int, int> curCoord = {start.first + i, start.second + i};
                    if (seafloor.find(curCoord) == seafloor.end())
                    {
                        seafloor.insert({curCoord, 1});
                    }
                    else
                    {
                        seafloor[curCoord]++;
                    }
                }
            }
            else //+- or -+
            {
                if (start.first > end.first) //-+
                {
                    for (int i = 0; start.first - i >= end.first; i++)
                    {
                        pair<int, int> curCoord = {start.first - i, start.second + i};
                        if (seafloor.find(curCoord) == seafloor.end())
                        {
                            seafloor.insert({curCoord, 1});
                        }
                        else
                        {
                            seafloor[curCoord]++;
                        }
                    }
                }
                else //+-
                {
                    for (int i = 0; start.second - i >= end.second; i++)
                    {
                        pair<int, int> curCoord = {start.first + i, start.second - i};
                        if (seafloor.find(curCoord) == seafloor.end())
                        {
                            seafloor.insert({curCoord, 1});
                        }
                        else
                        {
                            seafloor[curCoord]++;
                        }
                    }
                }
            }
        }
    }
    int overlap = 0;
    for (auto it = seafloor.begin(); it != seafloor.end(); it++)
    {
        if ((*it).second >= 2)
        {
            overlap++;
        }
    }
    cout << overlap << endl;
}