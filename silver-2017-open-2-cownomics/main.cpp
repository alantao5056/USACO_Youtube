#include <bits/stdc++.h>

using namespace std;

int N, M;

int toBase4(int a, int b, int c)
{
    return a*16 + b*4 + c;
}

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    cin >> N >> M;

    vector<vector<int>> spotty(N, vector<int>(M));
    vector<vector<int>> plain(N, vector<int>(M));

    // spotty
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'A')
            {
                spotty[i][j] = 0;
            } else if (s[j] == 'C')
            {
                spotty[i][j] = 1;
            } else if (s[j] == 'G')
            {
                spotty[i][j] = 2;
            } else // s[j] == 'T'
            {
                spotty[i][j] = 3;
            }
        }
    }

    // plain
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'A')
            {
                plain[i][j] = 0;
            } else if (s[j] == 'C')
            {
                plain[i][j] = 1;
            } else if (s[j] == 'G')
            {
                plain[i][j] = 2;
            } else // s[j] == 'T'
            {
                plain[i][j] = 3;
            }
        }
    }

    // try all combs
    int result = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = i+1; j < M; j++)
        {
            for (int k = j+1; k < M; k++)
            {
                // spotty
                // convert all to base 4 (max: 333 b4 = 63 b10)
                set<int> s;
                for (int l = 0; l < N; l++)
                {
                    s.insert(toBase4(spotty[l][i], spotty[l][j], spotty[l][k]));
                }

                // check if any plain cows overlap
                bool flag = false;
                for (int l = 0; l < N; l++)
                {
                    int base4 = toBase4(plain[l][i], plain[l][j], plain[l][k]);
                    if (s.find(base4) != s.end())
                    {
                        // overlaps, combination is not unique for spotty and plain
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                {
                    result++;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
