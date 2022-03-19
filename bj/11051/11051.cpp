#include <bits/stdc++.h>

using namespace std;

int N, K;
int DP[1001][1001];
bool B[1001][1001];
int ans;

int dp(int n, int k) {
  if (B[n][k]) {
    return DP[n][k];
  } else if (k == 0) {
    B[n][k] = true;
    DP[n][k] = 1;
    return DP[n][k];
  } else if (k == n) {
    B[n][k] = true;
    DP[n][k] = 1;
    return DP[n][k];
  } else {
    int res1 = dp(n-1, k-1);
    int res2 = dp(n-1, k);
    B[n][k] = true;
    DP[n][k] = (res1 + res2) % 10007;
    return DP[n][k];
  }
}

void solve() {
  ans = dp(N, K);
}

int main() {
  scanf("%d %d", &N, &K);

  solve();

  printf("%d\n", ans);

  return 0;
}
