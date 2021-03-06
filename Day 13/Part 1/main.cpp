#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin("in.txt");

vector<pair<int, int>> dots;
int width;
int height;

void foldy(int y)
{
    int nh = max(height - y, y); // new height of paper
    int dh = abs(height - 2 * y);
    for (int i = 0; i < dots.size(); i++)
    {
        if (dots[i].second > y && height / 2 <= y)
        {
            dots[i].second = abs(dots[i].second - 2 * y);
        }
        if (dots[i].second < y && height / 2 > y)
        {
            dots[i].second += dh;
        }
        if (dots[i].second > y && height / 2 > y)
        {
            dots[i].second = height - dots[i].second;
        }
    }
    height = nh;
}

void foldx(int x)
{
    int nw = max(width - x, x); // new width of paper
    int dw = abs(width - 2 * x);
    for (int i = 0; i < dots.size(); i++)
    {
        if (dots[i].first > x && width / 2 <= x)
        {
            dots[i].first = abs(dots[i].first - 2 * x);
        }
        if (dots[i].first < x && width / 2 > x)
        {
            dots[i].first += dw;
        }
        if (dots[i].first > x && width / 2 > x)
        {
            dots[i].first = width - dots[i].first;
        }
    }
    width = nw;
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
        set<pair<int, int>> s;
        for (int i = 0; i < dots.size(); i++)
        {
            s.insert(dots[i]);
        }
        cout << s.size() << endl;
        break;
    }
}