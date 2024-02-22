#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
    }

    int tot = scores[N-1];
    int curMin = scores[N-1];
    double maxScore = 0;
    vector<int> result;
    for (int i = N-2; i >= 1; i--)
    {
        tot += scores[i];
        curMin = min(curMin, scores[i]);
        double score = (double)(tot - curMin) / (N-i-1);

        if (fabs(maxScore - score) < 0.001) // same score
        {
            result.push_back(i);
        } else if (score > maxScore)
        {
            maxScore = score;
            result.clear();
            result.push_back(i);
        }
    }

    for (int i = result.size()-1; i >= 0; i--) {
        cout << result[i] << endl;
    }

    return 0;
}
