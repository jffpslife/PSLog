#include <bits/stdc++.h>

using namespace std;

int N;
int x[51];
int y[51];
int ans[51];

void solve() {
  for (int i = 0; i < N; i++) {
    ans[i] = 1;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        if (x[j] > x[i] && y[j] > y[i]) {
          ans[i]++;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  solve();

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
