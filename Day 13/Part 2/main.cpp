#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

vector<pair<int, int>> dots;
int width;
int height;

void foldy(int y)
{
    for (int i = 0; i < dots.size(); i++)
    {
        if (dots[i].second > y)
        {
            dots[i].second = 2 * y - dots[i].second;
        }
    }
    height = y;
}

void foldx(int x)
{
    for (int i = 0; i < dots.size(); i++)
    {
        if (dots[i].first > x)
        {
            dots[i].first = 2 * x - dots[i].first;
        }
    }
    width = x;
}

int main()
{
    string s;
    while (fin >> s)
    {
        if (s == "stop")
            break;
        string s1 = "";
        string s2 = "";
        bool ss = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ',')
            {
                ss = true;
            }
            else
            {
                if (!ss)
                {
                    s1 += s[i];
                }
                else
                {
                    s2 += s[i];
                }
            }
        }
        width = max(stoi(s1), width);
        height = max(stoi(s2), height);
        dots.push_back({stoi(s1), stoi(s2)});
    }

    set<pair<int, int>> se;
    // int total = 0;
    for (int i = 0; i < dots.size(); i++)
    {
        se.insert(dots[i]);
    }

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (se.find({j, i}) != se.end())
            {
                // total++;
                fout << "#";
            }
            else
            {
                fout << ".";
            }
        }
        fout << endl;
    }
    fout << endl;

    string instruct;
    while (fin >> instruct)
    {
        string val = "";
        for (int i = 2; i < instruct.size(); i++)
        {
            val += instruct[i];
        }
        int num = stoi(val);
        if (instruct[0] == 'y')
        {
            foldy(num);
        }
        else
        {
            foldx(num);
        }
        set<pair<int, int>> se;
        // int total = 0;
        for (int i = 0; i < dots.size(); i++)
        {
            se.insert(dots[i]);
        }

        for (int i = 0; i <= height; i++)
        {
            for (int j = 0; j <= width; j++)
            {
                if (se.find({j, i}) != se.end())
                {
                    // total++;
                    fout << "#";
                }
                else
                {
                    fout << ".";
                }
            }
            fout << endl;
        }
        fout << endl;
    }
    // cout << total << endl;
}