#include <bits/stdc++.h>

using namespace std;

int N;
int T[501][501];

int DP[501][501];
int ans;

void solve() {
  DP[1][1] = T[1][1];

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == 1) {
        DP[i][1] = DP[i-1][1] + T[i][1];
      } else if (j == i) {
        DP[i][i] = DP[i-1][i-1] + T[i][i];
      } else {
        DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + T[i][j];
      }
    }
  }

  ans = DP[N][1];
  for (int i = 2; i <= N; i++) {
    ans = max(ans, DP[N][i]);
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      scanf("%d", &T[i][j]);
    }
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
