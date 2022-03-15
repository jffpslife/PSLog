#include <bits/stdc++.h>

using namespace std;

int N;
int DP[101][10];

int ans = 0;

void solve() {
  for (int i = 0; i < 10; i++) {
    DP[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        DP[i][j] = DP[i-1][j+1];
      } else if (j == 9) {
        DP[i][j] = DP[i-1][j-1];
      } else {
        DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
      }
    }
  }

  for (int i = 1; i < 10; i++) {
    ans += DP[N][i];
    ans = ans % 1000000000;
  }
}

int main() {
  scanf("%d", &N);

  solve();

  printf("%d\n", ans);

  return 0;
}
