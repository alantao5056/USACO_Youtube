#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, Q;
vector<vector<pii>> adj;

int solve(int k, int v) {
  deque<int> q;
  vector<bool> visited(N, false);
  q.push_back(v);
  visited[v] = true;

  int ans = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    for (auto [nb, r] : adj[cur]) {
      if (!visited[nb] && r >= k) {
        q.push_back(nb);
        visited[nb] = true;
        ans++;
      }
    }
  }
  
  return ans;
}

int main() {
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  cin >> N >> Q;

  adj.resize(N, vector<pii>());
  for (int i = 0; i < N-1; i++) {
    int p, q, r; cin >> p >> q >> r; p--; q--;
    adj[p].push_back({q, r});
    adj[q].push_back({p, r});
  }

  while (Q--) {
    int k, v; cin >> k >> v; v--;

    cout << solve(k, v) << endl;
  }

  return 0;
}
