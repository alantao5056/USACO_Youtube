#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  cin >> N;
  vector<int> to(N);
  for (int i = 0; i < N; i++) {
    cin >> to[i];
    to[i]--;
  }

  vector<int> visited(N, -1); // records the cycle id
  int result = 0;
  for (int i = 0; i < N; i++) {
    if (visited[i] != -1) continue;

    int cur = i;
    while (visited[cur] == -1) {
      visited[cur] = i;
      cur = to[cur];
    }

    if (visited[cur] == i) {
      // it's our own cycle
      // cycle it again and count
      int temp = cur;
      do {
        result++;
        cur = to[cur];
      } while (cur != temp);
    }
  }

  cout << result << endl;

  return 0;
}