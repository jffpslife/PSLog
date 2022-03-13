#include <bits/stdc++.h>

using namespace std;

int N, M;
char board[51][51]; // N M

int ans;

void solve() {
  ans = 64;
  for (int i = 0; i < N - 7; i++) {
    for (int j = 0; j < M - 7; j++) {
      int b = 0;
      int w = 0;
      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
          if (board[i+x][j+y] == 'B') {
            if ((x + y) % 2 == 1) {
              b += 1;
            } else {
              w += 1;
            }
          } else {
            if ((x + y) % 2 == 1) {
              w += 1;
            } else {
              b += 1;
            }
          }
        }
      }
      ans = min(ans, min(b, w));
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  solve();

  cout << ans << endl;

  return 0;
}
