#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;

int ans;

int DP[30][30];
bool B[30][30];

int dp (int m, int n) {
  if (B[m][n]) {
    return DP[m][n];
  } else if (n == 0) {
    B[m][n] = true;
    DP[m][n] = 1;
    return DP[m][n];
  } else if (n == m) {
    B[m][n] = true;
    DP[m][n] = 1;
    return DP[m][n];
  } else {
    int res1 = dp(m-1, n-1);
    int res2 = dp(m-1, n);
    B[m][n] = true;
    DP[m][n] = res1 + res2;
    return DP[m][n];
  }
}

void solve() {
  ans = dp(M, N);
}

int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d %d", &N, &M);

    solve();

    printf("%d\n", ans);
  }

  return 0;
}
