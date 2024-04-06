#include <bits/stdc++.h>

using namespace std;

int N, G;

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  cin >> N >> G;

  map<int, int> cowMilk;
  cowMilk[0] = G;

  map<int, int> milkCow;
  milkCow[G] = INT_MAX;

  vector<vector<int>> logs(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    cin >> logs[i][0] >> logs[i][1] >> logs[i][2];
    cowMilk[logs[i][1]] = G;
  }
  
  sort(logs.begin(), logs.end());

  int topMilk = G;
  int cows = INT_MAX;
  int result = 0;

  for (int i = 0; i < N; i++) {
    int milk = cowMilk[logs[i][1]];
    int newMilk = milk + logs[i][2];

    // update cowMilk
    cowMilk[logs[i][1]] = newMilk;

    // update milkCow
    milkCow[milk]--;
    if (milkCow[milk] == 0) milkCow.erase(milk);
    milkCow[newMilk]++;

    // new top scores    
    int newTopMilk = milkCow.rbegin()->first;
    int newCows = milkCow.rbegin()->second;

    if (newTopMilk != topMilk || newCows != cows) {
      if (cows == 1 && newCows == 1 && milk == topMilk && newTopMilk == newMilk) {
        // corner case: when the top milk cow changes and still is top milk cow
        topMilk = newTopMilk;
        continue;
      }
      result++;
      topMilk = newTopMilk;
      cows = newCows;
    }
  }

  cout << result << endl;

  return 0;
}