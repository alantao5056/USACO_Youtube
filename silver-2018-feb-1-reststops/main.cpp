#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int L, N, rf, rb;

int main() {
  freopen("reststops.in", "r", stdin);
  freopen("reststops.out", "w", stdout);
  
  cin >> L >> N >> rf >> rb;

  vector<pii> rests(N); // c, -x
  for (int i = 0; i < N; i++) {
    cin >> rests[i].second >> rests[i].first;
    rests[i].second *= -1;
  }

  sort(rests.begin(), rests.end(), greater<>());

  ll ans = 0;
  int pos = 0;

  for (pii r : rests) {
    int x = -r.second;
    int c = r.first;

    if (x < pos) continue;
    int d = x-pos;
    ans += (ll) ( (ll) d*(rf-rb)) * c;
    pos = x;
  }
  
  cout << ans << endl;
  
  return 0;
}
