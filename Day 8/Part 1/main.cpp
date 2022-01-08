#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("in.txt");

int main()
{
    string s1;
    string s2;
    int total = 0;
    while (getline(fin, s1))
    {
        s2 = s1.substr(s1.find('|') + 1);
        string num = "";
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ' ')
            {
                if (num.size() == 2 || num.size() == 4 || num.size() == 3 || num.size() == 7)
                {
                    total++;
                }
                num = "";
            }
            else
            {
                num += s2[i];
            }
        }
        if (num.size() == 2 || num.size() == 4 || num.size() == 3 || num.size() == 7)
        {
            total++;
        }
    }
    cout << total << endl;
}