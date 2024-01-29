#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    cin >> N;

    // initialize grid
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = s[j]-'A';
        }
    }

    // try all possible combinations
    vector<vector<int>> PCL; // [i1, j1, i2, j2]
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i1 = 0; i1 < N; i1++)
    {
        for (int j1 = 0; j1 < N; j1++)
        {
            for (int i2 = i1; i2 < N; i2++)
            {
                for (int j2 = j1; j2 < N; j2++)
                {
                    // check if current is contained in any PCL
                    bool flag = false;
                    for (vector<int> p : PCL)
                    {
                        if (i1 >= p[0] && j1 >= p[1] && i2 <= p[2] && j2 <= p[3])
                        {
                            // contained
                            flag = true;
                            break;
                        }
                    }

                    if (flag) continue;

                    // check if this is a pcl
                    int c1 = -1;
                    int c2 = -1;
                    int c1Num = 0;
                    int c2Num = 0;
                    for (int i = i1; i <= i2; i++)
                    {
                        if (flag) break;
                        for (int j = j1; j <= j2; j++)
                        {
                            if (visited[i][j]) continue;

                            // check if this color is valid
                            int color = grid[i][j];
                            if (c1 == -1)
                            {
                                c1 = color;
                                c1Num++;
                            } else if (c2 == -1)
                            {
                                c2 = color;
                                c2Num++;
                            } else
                            {
                                if (color == c1) c1Num++;
                                else if (color == c2) c2Num++;
                                else { // we found a third color
                                    flag = true;
                                    break;
                                }
                                if (c1Num >= 2 && c2Num >= 2) // no single region
                                {
                                    flag = true;
                                    break;
                                }
                            }

                            deque<int> qi; qi.push_back(i);
                            deque<int> qj; qj.push_back(j);
                            visited[i][j] = true;

                            while (!qi.empty())
                            {
                                int i_ = qi.front(); qi.pop_front();
                                int j_ = qj.front(); qj.pop_front();

                                // up
                                if (i_-1 >= i1 && !visited[i_-1][j_] && grid[i_-1][j_] == color)
                                {
                                    qi.push_back(i_-1);
                                    qj.push_back(j_);
                                    visited[i_-1][j_] = true;
                                }
                                // down
                                if (i_+1 <= i2 && !visited[i_+1][j_] && grid[i_+1][j_] == color)
                                {
                                    qi.push_back(i_+1);
                                    qj.push_back(j_);
                                    visited[i_+1][j_] = true;
                                }
                                // left
                                if (j_-1 >= j1 && !visited[i_][j_-1] && grid[i_][j_-1] == color)
                                {
                                    qi.push_back(i_);
                                    qj.push_back(j_-1);
                                    visited[i_][j_-1] = true;
                                }
                                // right
                                if (j_+1 <= j2 && !visited[i_][j_+1] && grid[i_][j_+1] == color)
                                {
                                    qi.push_back(i_);
                                    qj.push_back(j_+1);
                                    visited[i_][j_+1] = true;
                                }
                            }
                        }
                    }

                    // change back visited
                    for (int i = i1; i <= i2; i++)
                    {
                        for (int j = j1; j <= j2; j++)
                        {
                            visited[i][j] = false;
                        }
                    }

                    if (flag || c1Num == 0 || c2Num == 0 || (c1Num == 1 && c2Num == 1)) continue;

                    // yay it's a pcl
                    // check if it contains any other pcls
                    vector<vector<int>>::iterator iter;
                    for (iter = PCL.begin(); iter != PCL.end();)
                    {
                        vector<int> cur = *iter;
                        if (i1 <= cur[0] && j1 <= cur[1] && i2 >= cur[2] && j2 >= cur[3])
                        {
                            iter = PCL.erase(iter);
                        } else
                        {
                            iter++;
                        }
                    }
                    PCL.push_back({i1, j1, i2, j2});
                }
            }
        }
    }

    cout << PCL.size() << endl;

    return 0;
}
