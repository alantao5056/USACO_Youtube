#include <bits/stdc++.h>

using namespace std;

int N, M, R;

int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  // read inputs
  cin >> N >> M >> R;

  vector<int> cows(N);
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }

  sort(cows.begin(), cows.end());

  vector<pair<int, int>> stores(M);
  for (int i = 0; i < M; i++) {
    //! price first, then quantity
    cin >> stores[i].second >> stores[i].first;
  }

  sort(stores.begin(), stores.end(), greater<>());

  vector<int> farmers(R);
  for (int i = 0; i < R; i++) {
    cin >> farmers[i];
  }

  sort(farmers.begin(), farmers.end(), greater<>());

  // solution
  long long total = 0;
  int left = 0;
  int right = N-1;
  int s = 0;
  int f = 0;

  while ((s < M || f < R) && left <= right) {
    if (s==M) {
      total += farmers[f];
      f++;
      left++;
      continue;
    }

    int sValue = 0;
    int ss = s;
    int newVal = 0;
    int milk = cows[right];
    while (ss < M) {
      if (stores[ss].second >= milk) {
        sValue += milk * stores[ss].first;
        newVal = stores[ss].second - milk;
        break;
      }
      sValue += stores[ss].second * stores[ss].first;
      milk -= stores[ss].second;
      ss++;
    }

    int fValue = f == R ? 0 : farmers[f];

    if (sValue >= fValue) {
      s = ss;
      if (s < M) {
        stores[s].second = newVal;
      }
      total += sValue;
      right--;
    } else {
      total += farmers[f];
      f++;
      left++;
    }
  }

  cout << total << endl;


  return 0;
}