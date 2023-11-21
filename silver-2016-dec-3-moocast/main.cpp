#include <bits/stdc++.h>

using namespace std;

int N;

struct Cow
{
    int x, y, range;
    bool visited = false;
};

double dist(Cow a, Cow b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;

    // construct cows vector
    vector<Cow> cows(N);

    for (int i = 0; i < N; i++)
    {
        cows[i] = Cow();
        cin >> cows[i].x >> cows[i].y >> cows[i].range;
    }

    // construct canReach vector
    vector<vector<int>> canReach(N, vector<int>());

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            double curDist = dist(cows[i], cows[j]);
            if (curDist <= cows[i].range)
            {
                canReach[i].push_back(j);
            }
            if (curDist <= cows[j].range)
            {
                canReach[j].push_back(i);
            }
        }
    }

    // getting the maximum in canReach
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        // start with this cow
        queue<int> q;
        q.push(i);

        vector<bool> visited(N);
        visited[i] = true;

        int cnt = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int nb : canReach[cur])
            {
                if (!visited[nb])
                {
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }

        result = max(result, cnt);
    }

    cout << result << endl;

    return 0;
}
