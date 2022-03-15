#include <bits/stdc++.h>

using namespace std;

int n;
int v[10001];
int DP0[10001];
int DP1[10001];
int DP2[10001];
int ans = 0;

void solve() {
  DP0[0] = 0;
  DP1[0] = 0;
  DP2[0] = 0;
  DP0[1] = 0;
  DP1[1] = v[1];
  DP2[1] = 0;

  for (int i = 2; i <= n; i++) {
    DP0[i] = max(DP0[i-1], max(DP1[i-1], DP2[i-1]));
    DP1[i] = DP0[i-1] + v[i];
    DP2[i] = DP1[i-1] + v[i];
  }

  ans = max(DP0[n], max(DP1[n], DP2[n]));
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }

  solve();

  printf("%d\n", ans);

  return 0;
}
