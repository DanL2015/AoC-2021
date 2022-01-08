// bingo: row col or diag
// nvm no diag

// this took me longer than i want to admit :/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

struct board
{
    int b[5][5];
    bool finished;
};

ifstream fin("in.txt");

string in;
vector<int> input;
set<int> notCompleted; // stores the board that haven't been completed

vector<board> boards;
vector<board> filled;

void updateboards(int inind)
{
    for (int i = 0; i < boards.size(); i++)
    {
        if (boards[i].finished)
            continue;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (boards[i].b[j][k] == input[inind])
                {
                    filled[i].b[j][k] = 1;
                }
            }
        }
    }
}

void checkCompletion()
{
    for (int i = 0; i < boards.size(); i++)
    {
        if (boards[i].finished)
            continue;
        // check horizontal
        for (int j = 0; j < 5; j++)
        {
            int completed = 0;
            for (int k = 0; k < 5; k++)
            {
                if (filled[i].b[j][k])
                {
                    completed++;
                }
            }
            if (completed == 5)
            {
                // cout << i << endl;
                boards[i].finished = true;
                filled[i].finished = true;
            }
        }
        // check vertical
        for (int j = 0; j < 5; j++)
        {
            int completed = 0;
            for (int k = 0; k < 5; k++)
            {
                if (filled[i].b[k][j])
                {
                    completed++;
                }
            }
            if (completed == 5)
            {
                // cout << i << endl;
                boards[i].finished = true;
                filled[i].finished = true;
            }
        }
    }
    return;
}

int checkLastBoard()
{
    int total = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (!boards[i].finished)
        {
            total++;
            // if (total > 1)
            // {
            //   return false;
            // }
        }
    }
    return total;
}

int main()
{
    fin >> in;

    // decipher input
    string cur = "";
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == ',')
        {
            input.push_back(stoi(cur));
            cur = "";
        }
        else
        {
            cur += in[i];
        }
    }

    board temp;
    while (fin >> temp.b[0][0])
    {
        for (int i = 0; i < 4; i++)
        {
            fin >> temp.b[0][i + 1];
        }
        for (int i = 1; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                fin >> temp.b[i][j];
            }
        }

        temp.finished = false;

        board filledTemp;
        // fill the result board with 0s
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                filledTemp.b[i][j] = 0;
            }
        }
        filled.push_back(filledTemp);
        boards.push_back(temp);
    }
    // Part 1
    //  int inind;
    //  for (inind=0; !checkCompletion(); inind++)
    //  {
    //    updateboards(inind);
    //  }

    // Part 2
    for (int i = 0; i < boards.size(); i++)
    {
        notCompleted.insert(i);
    }

    int inind;
    for (inind = 0;; inind++)
    {
        updateboards(inind);
        checkCompletion();
        int n = checkLastBoard();
        // cout << n << endl;
        if (n == 1)
            break;
    }

    // Get index of last board
    int completedInd = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (boards[i].finished == false)
        {
            completedInd = i;
        }
    }

    // cout << completedInd << endl;

    // Continue updating the board
    for (; boards[completedInd].finished == false; inind++)
    {
        updateboards(inind);
        checkCompletion();
    }

    int finalNum = input[inind - 1];
    int unmarkedSum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!filled[completedInd].b[i][j])
            {
                unmarkedSum += boards[completedInd].b[i][j];
            }
        }
    }
    cout << unmarkedSum << " " << finalNum << endl;
    cout << finalNum * unmarkedSum << endl;
}