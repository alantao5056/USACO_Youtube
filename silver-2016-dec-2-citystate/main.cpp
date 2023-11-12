#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    cin >> N;

    map<string, int> cs;

    for (int i = 0; i < N; i++)
    {
        string city, state;
        cin >> city >> state;

        cs[city.substr(0, 2) + state]++;
    }

    long long result = 0;
    for (auto const& [key, val] : cs)
    {
        string city = key.substr(0, 2);
        string state = key.substr(2, 4);

        if (city == state)
        {
            // special pairs have to be from different states
            continue;
        }

        result += (long) cs[state + city] * val;
    }

    cout << result/2 << endl;

    return 0;
}
