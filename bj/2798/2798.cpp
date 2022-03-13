#include <bits/stdc++.h>

using namespace std;

int N, M;
int cards[101];
int ans;

void solve() {
  for (int i = 0; i < N; i++) {
    cin >> cards[i];
  }

  ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        int s = cards[i] + cards[j] + cards[k];
        if (s <= M) {
          ans = max(ans, s);
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  solve();
  cout << ans << endl;

  return 0;
}
