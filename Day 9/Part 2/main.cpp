// Using bfs

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("in.txt");

vector<vector<int>> heightmap;
vector<vector<int>> visited;
vector<int> ans;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int main()
{
    string s;
    while (fin >> s)
    {
        vector<int> row;
        vector<int> brow;
        for (int i = 0; i < s.size(); i++)
        {
            row.push_back(s[i] - '0');
        }
        heightmap.push_back(row);
    }

    for (int i = 0; i < heightmap.size(); i++)
    {
        for (int j = 0; j < heightmap[i].size(); j++)
        {
            int total = 1;
            // bfs time
            // clear visited array
            visited.clear();
            for (int k = 0; k < heightmap.size(); k++)
            {
                vector<int> brow;
                for (int l = 0; l < heightmap[k].size(); l++)
                {
                    brow.push_back(0);
                }
                visited.push_back(brow);
            }

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;
            while (!q.empty()) // we only go to neighbors if they are larger height than us.
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int cx = cur.first + dx[k];
                    int cy = cur.second + dy[k];
                    if (cx < 0 || cy < 0 || cx >= visited.size() || cy >= visited[i].size())
                        continue;
                    if (!visited[cx][cy] && heightmap[cx][cy] != 9 && heightmap[cx][cy] > heightmap[cur.first][cur.second])
                    {
                        // cout << cx << " " << cy << endl;
                        visited[cx][cy] = 1;
                        q.push({cx, cy});
                        total++;
                    }
                }
            }
            // total
            ans.push_back(total);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] * ans[ans.size() - 2] * ans[ans.size() - 3] << endl;
}