#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int N, M, K;

int main() {
  // freopen("acrobatics.in", "r", stdin);
  // freopen("acrobatics.out", "w", stdout);

  cin >> N >> M >> K;

  map<int, int> cows;
  for (int i = 0; i < N; i++) {
    int w, a; cin >> w >> a;
    cows[w] = a;
  }

  map<int, int> cur;
  int bases = 0;
  ll total = 0;

  for (auto const& [w, a] : cows) {
    int w2 = w; int a2 = a;
    // adding bases
    if (bases != M) {
      if (a2 + bases > M) {
        a2 -= M-bases;
        cur[w2] = M-bases;
        total += M-bases;
        bases = M;
      } else {
        bases += a;
        total += a;
        cur[w2] = a;
        continue;
      }
    }
    
    // stacking
    vector<int> rem;
    ll curTot = 0;
    for (auto const& [cw, ca] : cur) {
      if (cw + K <= w2) {
        // can stack
        if (a2 >= ca) {
          // can stack all
          a2 -= ca;
          curTot += ca;
          rem.push_back(cw);
        } else {
          // partly stack
          cur[cw] -= a2;
          curTot += a2;
          break;
        }
      } else {
        break;
      }
    }

    total += curTot;
    if (curTot != 0) {
      cur[w2] = curTot;
    }

    for (int r : rem) {
      cur.erase(r);
    }
  }

  cout << total << endl;

  return 0;
}