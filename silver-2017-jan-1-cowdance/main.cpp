#include <bits/stdc++.h>

using namespace std;

int N, T;

bool works(vector<int>& cows, int K)
{
    vector<int> stage(K);

    int i = 0; // i is the index of the current cow
    for (; i < K; i++)
    {
        stage[i] = cows[i];
    }

    // simulate
    int total = 0; // final result
    bool flag = false; // flag represents if we have ran out of cows or not
    while (!flag)
    {
        int minDance = INT_MAX; // the minimum time it takes for a cow to get off stage
        for (int j = 0; j < K; j++)
        {
            minDance = min(minDance, stage[j]);
        }

        total += minDance;

        for (int j = 0; j < K; j++)
        {
            stage[j] -= minDance;
            if (stage[j] == 0)
            {
                // this cow is getting off
                // replace it with the next cow
                if (i != N)
                {
                    stage[j] = cows[i];
                    i++;
                } else
                {
                    // we ran out of cows
                    flag = true;
                }
            }
        }
    }

    int remain = 0; // the remaining time
    for (int j = 0; j < K; j++)
    {
        remain = max(remain, stage[j]);
    }

    return (total + remain) <= T;
}

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    // read input
    cin >> N >> T;

    vector<int> cows(N);
    for (int i = 0; i < N; i++)
    {
        cin >> cows[i];
    }

    // binary search
    int low = 1;
    int high = N;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (works(cows, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;

    return 0;
}
