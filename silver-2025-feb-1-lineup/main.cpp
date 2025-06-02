#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int _ = 0; _ < T; _++) {
    int N;
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
      cin >> cows[i];
    }

    // big contain and after this one
    vector<int> big(N+1);
    int m = 0;
    for (int i = N-1; i >= 0; i--) {
      m = max(m, cows[i]);
      big[i] = m;
    }

    int start = -1;
    int cur = 0;

    while (start < N-1) {
      int bbig = 0;
      while (cows[cur] != big[start+1]) {
        bbig = max(bbig, cows[cur]);
        cur++;
      }

      if (bbig >= big[cur+1]) {
        // can use
        int temp = cows[cur];
        cows.erase(cows.begin() + cur);
        cows.insert(cows.begin() + start+1, temp);
        break;
      }

      start = cur;
      cur++;
    }

    // reconstruct
    m = 0;
    for (int i = N-1; i >= 0; i--) {
      m = max(m, cows[i]);
      big[i] = m;
    }

    // calc
    vector<int> res;
    int b = big[0];
    for (int i = 0; i < N; i++) {
      if (cows[i] == b) {
        res.push_back(b);
        b = big[i+1];
      }
    }

    for (int i = 0; i < res.size()-1; i++) {
      cout << res[i] << " ";
    }

    cout << res[res.size()-1];

    cout << endl;
  }

  return 0;
}