#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N;

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  cin >> N;

  vector<pii> lg(N);
  for (int i = 0; i < N; i++) {
    cin >> lg[i].first >> lg[i].second;
  } 

  sort(lg.begin(), lg.end());
  
  // get total time
  int total = 0;
  int curStart = lg[0].first;
  int curEnd = lg[0].second;
  bool submerged = false;
  for (int i = 1; i < N; i++) {
    if (lg[i].second <= lg[i-1].second) {
      // completely submerged
      submerged = true;
    }
    if (lg[i].first > curEnd) {
      // separated from prev block
      total += curEnd - curStart;
      curStart = lg[i].first;
      curEnd = lg[i].second;
    } else {
      // connected
      curEnd = max(curEnd, lg[i].second);
    }
  }

  total += curEnd - curStart;
  if (submerged) {
    cout << total << endl;
    return 0;
  }

  // get which one to fire
  int aloneTime = INT_MAX;
  for (int i = 0; i < N; i++) {
    int left = 0;
    if (i > 0) {
      left = max(0, lg[i-1].second - lg[i].first);
    }

    int right = 0;
    if (i < N-1) {
      right = max(0, lg[i].second - lg[i+1].first);
    }

    int alone = max(0, lg[i].second - lg[i].first - left - right);
    aloneTime = min(aloneTime, alone);
  }

  cout << total - aloneTime << endl;

  return 0;
}