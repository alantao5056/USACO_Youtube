#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    cin >> N;
    vector<pair<int, int>> cows(N); // first = num of cows     second = milking time
    for (int i = 0; i < N; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });

    int left = 0;
    int right = N-1;

    int result = 0;
    while (left < right)
    {
        result = max(result, cows[left].second + cows[right].second);
        if (cows[left].first < cows[right].first) // left has less cows
        {
            cows[right].first -= cows[left].first;
            cows[left].first = 0;
            left++;
        } else if (cows[right].first < cows[left].first) // right has less cows
        {
            cows[left].first -= cows[right].first;
            cows[right].first = 0;
            right--;
        } else // same number of cows
        {
            cows[left].first = 0;
            cows[right].first = 0;
            left++; right--;
        }
    }

    // left == right
    if (left == right && cows[left].first > 0) // one group left over
    {
        result = max(result, cows[left].second * 2);
    }

    cout << result << endl;

    return 0;
}
