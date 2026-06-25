#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, B;

int main() {
  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  cin >> N >> B;
  vector<int> snow(N);
  for (int i = 0; i < N; i++) {
    cin >> snow[i];
  }

  vector<pii> boots(B);
  for (int i = 0; i < B; i++) {
    cin >> boots[i].first >> boots[i].second;
  }

  vector<vector<bool>> dp(N, vector<bool>(B, false));
  dp[0][0] = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < B; j++) {
      // can step
      if (boots[j].first < snow[i]) continue;

      // switched on
      for (int k = 0; k < j; k++) {
        if (dp[i][k]) {
          dp[i][j] = true;
          break;
        }
      }

      // moved to
      for (int k = 1; k <= min(boots[j].second, i); k++) {
        if (dp[i-k][j]) {
          dp[i][j] = true;
          continue;
        }
      }
    }
  }

  for (int j = 0; j < B; j++) {
    if (dp[N-1][j]) {
      cout << j << endl;
      break;
    }
  }

  return 0;
}
