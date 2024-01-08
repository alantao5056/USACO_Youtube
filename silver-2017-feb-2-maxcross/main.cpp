#include <bits/stdc++.h>

using namespace std;

int N, K, B;

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    cin >> N >> K >> B;
    vector<bool> signals(N, true); // true = working signal, false = damaged signal
    for (int i = 0; i < B; i++)
    {
        int cur;
        cin >> cur;
        cur--;
        signals[cur] = false;
    }

    // create initial window
    int broken = 0;
    for (int i = 0; i < K; i++)
    {
        if (!signals[i])
        {
            broken++;
        }
    }

    // sliding window
    int result = broken;
    for (int i = 1; i <= N-K; i++)
    {
        if (!signals[i-1])
        {
            broken--;
        }
        if (!signals[i+K-1])
        {
            broken++;
        }

        result = min(result, broken);
    }

    cout << result << endl;

    return 0;
}
