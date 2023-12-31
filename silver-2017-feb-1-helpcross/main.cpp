#include <bits/stdc++.h>

using namespace std;

int C, N;

int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    cin >> C >> N;

    vector<int> chickens(C);
    for (int i = 0; i < C; i++)
    {
        cin >> chickens[i];
    }

    sort(chickens.begin(), chickens.end());

    vector<pair<int, int>> cows(N);
    vector<bool> visited(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    // start finding pairs
    int result = 0;
    for (int i = 0; i < C; i++)
    {
        int minEnd = INT_MAX;
        int minIdx = -1;
        for (int j = 0; j < N; j++)
        {
            if (!visited[j] && chickens[i] >= cows[j].first && chickens[i] <= cows[j].second)
            {
                if (cows[j].second < minEnd)
                {
                    minEnd = cows[j].second;
                    minIdx = j;
                }
            }
        }

        if (minIdx != -1)
        {
            // found
            result++;
            visited[minIdx] = true;
        }
    }

    cout << result << endl;

    return 0;
}
