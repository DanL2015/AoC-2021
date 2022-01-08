#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("in.txt");

int main()
{
    // Part 2
    vector<int> nums;
    int temp;
    int total = 0;
    while (fin >> temp)
    {
        nums.push_back(temp);
    }
    int next = 0;
    int prev = nums[0] + nums[1] + nums[2];

    for (int i = 1; i < nums.size() - 2; i++)
    {
        next = nums[i] + nums[i + 1] + nums[i + 2];
        if (next > prev)
        {
            total++;
        }
        prev = next;
    }
    cout << total << endl;
}