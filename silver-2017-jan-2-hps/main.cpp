#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> N;

    vector<char> fj(N);

    // counts for right side
    int h2 = 0;
    int p2 = 0;
    int s2 = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> fj[i];
        if (fj[i] == 'H')
        {
            h2++;
        }
        else if (fj[i] == 'P')
        {
            p2++;
        }
        else
        {
            s2++;
        }
    }

    // counts for left side
    int h1 = 0;
    int p1 = 0;
    int s1 = 0;

    int result = 0;

    for (int i = 0; i < N; i++)
    {
        // change the current counts
        if (fj[i] == 'H')
        {
            h1++;
            h2--;
        }
        else if (fj[i] == 'P')
        {
            p1++;
            p2--;
        }
        else
        {
            s1++;
            s2--;
        }

        // calculate wins
        int leftWin = max(h1, max(p1, s1));
        int rightWin = max(h2, max(p2, s2));
        result = max(result, leftWin + rightWin);
    }

    cout << result << endl;

    return 0;
}
