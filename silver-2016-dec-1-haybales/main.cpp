#include <bits/stdc++.h>
using namespace std;

int N, Q;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin >> N >> Q;
    vector<int> haybales(N);

    for (int i = 0; i < N; i++)
    {
        cin >> haybales[i];
    }

    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        int aIdx = lower_bound(haybales.begin(), haybales.end(), a) - haybales.begin();
        int bIdx = upper_bound(haybales.begin(), haybales.end(), b) - haybales.begin();

        cout << bIdx - aIdx << endl;
    }

    return 0;
}
