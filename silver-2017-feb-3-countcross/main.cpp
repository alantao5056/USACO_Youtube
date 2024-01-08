#include <bits/stdc++.h>

using namespace std;

int N, K, R;

int main()
{
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> N >> K >> R;

    vector<vector<vector<bool>>> grid(N+2, vector<vector<bool>>(N+2, vector<bool>(6, false)));
    // vector<bool> = {up, down, left, right, cow, visited}

    // build outer wall
    for (int i = 1; i <= N; i++)
    {
        grid[1][i][0] = true; // up wall
        grid[N][i][1] = true; // down wall
        grid[i][1][2] = true; // left wall
        grid[i][N][3] = true; // right wall
    }

    // read roads
    for (int i = 0; i < R; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        if (r1 == r2) // left or right
        {
            int leftC = min(c1, c2);
            int rightC = max(c1, c2);
            grid[r1][leftC][3] = true; // right = true
            grid[r1][rightC][2] = true; // left = true
        } else // up or down
        {
            int upR = min(r1, r2);
            int downR = max(r1, r2);
            grid[upR][c1][1] = true; // down = true
            grid[downR][c1][0] = true; // up = true
        }
    }

    // read cows
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;

        grid[r][c][4] = true; // cow = true
    }

    // flood fill
    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (grid[i][j][5]) continue; // already visited
            queue<int> qi;
            queue<int> qj;
            qi.push(i);
            qj.push(j);
            grid[i][j][5] = true; // visited = true
            int cowCount = 0;

            while (!qi.empty())
            {
                int curI = qi.front(); qi.pop();
                int curJ = qj.front(); qj.pop();

                cowCount += grid[curI][curJ][4];

                if (!grid[curI][curJ][0] && !grid[curI-1][curJ][5]) // up and not visited
                {
                    qi.push(curI-1); qj.push(curJ);
                    grid[curI-1][curJ][5] = true;
                }

                if (!grid[curI][curJ][1] && !grid[curI+1][curJ][5]) // down and not visited
                {
                    qi.push(curI+1); qj.push(curJ);
                    grid[curI+1][curJ][5] = true;
                }

                if (!grid[curI][curJ][2] && !grid[curI][curJ-1][5]) // left and not visited
                {
                    qi.push(curI); qj.push(curJ-1);
                    grid[curI][curJ-1][5] = true;
                }

                if (!grid[curI][curJ][3] && !grid[curI][curJ+1][5]) // right and not visited
                {
                    qi.push(curI); qj.push(curJ+1);
                    grid[curI][curJ+1][5] = true;
                }
            }

            result += cowCount * (K-cowCount);
        }
    }

    cout << result/2 << endl;

    return 0;
}
